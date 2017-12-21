#include "AbstractVM.hpp"

// STATIC ########################################################

AbstractVmHandler AbstractVmHandler::m_instance = AbstractVmHandler();

AbstractVmHandler &			AbstractVmHandler::Singleton( void )
{
	return (m_instance);
}

// ###############################################################

// CANONICAL #####################################################

AbstractVmHandler::AbstractVmHandler ( void )
{
	this->operationsMethods[VmOperation_push] = &AbstractVmHandler::handleOperationPush;
	this->operationsMethods[VmOperation_pop] = &AbstractVmHandler::handleOperationPop;
	this->operationsMethods[VmOperation_dump] = &AbstractVmHandler::handleOperationDump;
	this->operationsMethods[VmOperation_assert] = &AbstractVmHandler::handleOperationAssert;
	this->operationsMethods[VmOperation_print] = &AbstractVmHandler::handleOperationPrint;
	this->operationsMethods[VmOperation_exit] = &AbstractVmHandler::handleOperationExit;
	this->operationsMethods[VmOperation_add] = &AbstractVmHandler::handleOperationAdd;
	this->operationsMethods[VmOperation_sub] = &AbstractVmHandler::handleOperationSub;
	this->operationsMethods[VmOperation_mul] = &AbstractVmHandler::handleOperationMul;
	this->operationsMethods[VmOperation_div] = &AbstractVmHandler::handleOperationDiv;
	this->operationsMethods[VmOperation_mod] = &AbstractVmHandler::handleOperationMod;
	this->operationsMethods[VmOperation_mov] = &AbstractVmHandler::handleOperationMov;
	this->operationsMethods[VmOperation_copy] = &AbstractVmHandler::handleOperationCopy;
	this->operationsMethods[VmOperation_inc] = &AbstractVmHandler::handleOperationInc;
	this->operationsMethods[VmOperation_dec] = &AbstractVmHandler::handleOperationDec;

	this->pushOperationsMapKey["INT8"] = t_Int8;
	this->pushOperationsMapKey["INT16"] = t_Int16;
	this->pushOperationsMapKey["INT32"] = t_Int32;
	this->pushOperationsMapKey["INT64"] = t_Int64;
	this->pushOperationsMapKey["FLOAT"] = t_Float;
	this->pushOperationsMapKey["DOUBLE"] = t_Double;

	this->operationsMapKey["PUSH"] = VmOperation_push;
	this->operationsMapKey["POP"] = VmOperation_pop;
	this->operationsMapKey["DUMP"] = VmOperation_dump;
	this->operationsMapKey["ASSERT"] = VmOperation_assert;
	this->operationsMapKey["PRINT"] = VmOperation_print;
	this->operationsMapKey["EXIT"] = VmOperation_exit;
	this->operationsMapKey["ADD"] = VmOperation_add;
	this->operationsMapKey["SUB"] = VmOperation_sub;
	this->operationsMapKey["MUL"] = VmOperation_mul;
	this->operationsMapKey["DIV"] = VmOperation_div;
	this->operationsMapKey["MOD"] = VmOperation_mod;
	this->operationsMapKey["MOV"] = VmOperation_mov;
	this->operationsMapKey["COPY"] = VmOperation_copy;
	this->operationsMapKey["INC"] = VmOperation_inc;
	this->operationsMapKey["DEC"] = VmOperation_dec;
	return ;
}

AbstractVmHandler::AbstractVmHandler ( AbstractVmHandler const & src )
{
	*this = src;
	return ;
}

AbstractVmHandler &			AbstractVmHandler::operator=( AbstractVmHandler const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

AbstractVmHandler::~AbstractVmHandler ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, AbstractVmHandler const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

void						AbstractVmHandler::handleVmOperation(std::string const & cmd, std::string const & value)
{
	std::string const	upper_cmd = strtoupper(cmd);
	eVmOperationType 	operation_type;

	if (this->operationsMapKey.count(upper_cmd) == 0)
		UNKNOW_VM_OPERATION_EXCEPTION("Unknow vm operation : " + cmd);
	operation_type = this->operationsMapKey.at(upper_cmd);
	(*this.*operationsMethods[operation_type])(value);
}

// ###############################################################

// PRIVATE METHOD ################################################

void						AbstractVmHandler::handleOperationPush(std::string const & value)
{
	std::regex 			type_regex("(\\S.*)\\(");
	std::regex 			value_regex("\\(([^)]+)\\)");
	std::smatch 		base_match;
	std::string			upper_pus_op;
	eOperandType		type;
	std::string			number;

	if (std::regex_search(value, base_match, type_regex) == false || base_match.size() != 2)
		SYNTAX_EXCEPTION("Syntax error on \"push " + value + "\"");
	upper_pus_op = strtoupper(base_match.str(1));
	if (this->pushOperationsMapKey.count(upper_pus_op) == 0)
		UNKNOW_OPERAND_EXCEPTION("Unknow operand type : " + base_match.str(1));
	type = this->pushOperationsMapKey.at(upper_pus_op);
	if (std::regex_search(value, base_match, value_regex) == false || base_match.size() != 2)
		SYNTAX_EXCEPTION("Syntax error on \"push " + value + "\"");
	if (is_numeric(base_match.str(1)) == false)
		NUMBER_FORMAT_EXCEPTION("Error number format : " + value);
	this->stack.push(OperandFactory::Singleton().createOperand(type, base_match.str(1)));
}

void						AbstractVmHandler::handleOperationPop(std::string const & value)
{
	size_t					number;

	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	if (is_numeric(value) == false)
		number = 1;
	else
		number = std::stoi(value);
	if (number > this->stack.size())
		STACK_TO_SMALL_EXCEPTION("stack size < " + value);
	for (unsigned int i = 0; i < number; i++)
		this->stack.pop();//Remove top element
}

std::ostream &				operator<<(std::ostream & o, std::stack<const IOperand *> i)
{
	IOperand const *element;

	while (!i.empty())
	{
		element = i.top();
		o << element->toString() << std::endl;
		i.pop();
	}
	return (o);
}

void						AbstractVmHandler::handleOperationDump(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	std::cout << this->stack << std::endl;
}

void						AbstractVmHandler::handleOperationAssert(std::string const & value)
{
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	IOperand const		*it = this->stack.top();
	std::regex 			type_regex("(\\S.*)\\(");
	std::regex 			value_regex("\\(([^)]+)\\)");
	std::smatch 		base_match;
	std::string			upper_pus_op;
	eOperandType		type;
	std::string			number;

	if (std::regex_search(value, base_match, type_regex) == false || base_match.size() != 2)
		SYNTAX_EXCEPTION("Syntax error on \"assert " + value + "\"");
	upper_pus_op = strtoupper(base_match.str(1));
	if (this->pushOperationsMapKey.count(upper_pus_op) == 0)
		UNKNOW_OPERAND_EXCEPTION("Unknow operand type : " + base_match.str(1));
	type = this->pushOperationsMapKey.at(upper_pus_op);
	if (std::regex_search(value, base_match, value_regex) == false || base_match.size() != 2)
		SYNTAX_EXCEPTION("Syntax error on \"assert " + value + "\"");
	number = base_match.str(1);
	if (is_numeric(number) == false)
		NUMBER_FORMAT_EXCEPTION("Error number format : " + value);

	if (type != it->getType() || number != it->toString())
	{
		INVALID_ASSERT_EXCEPTION("Assert invalid : " + number + " != " + it->toString() + " or type not equals");
	}
}

void						AbstractVmHandler::handleOperationAdd(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	result = *first + *second;
	this->stack.push(result);
}

void						AbstractVmHandler::handleOperationSub(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	result = *first - *second;
	this->stack.push(result);
}

void						AbstractVmHandler::handleOperationMul(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	result = *first * *second;
	this->stack.push(result);
}

void						AbstractVmHandler::handleOperationDiv(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	result = *first / *second;
	this->stack.push(result);
}

void						AbstractVmHandler::handleOperationMod(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	result = *first % *second;
	this->stack.push(result);
}

void						AbstractVmHandler::handleOperationMov(std::string const & value)
{
	std::list<IOperand const *>	lst;
	IOperand const				*mover;
	size_t						number;

	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	if (is_numeric(value) == false)
		NUMBER_FORMAT_EXCEPTION("Error number format : " + value);
	number = std::stoi(value);
	if (number > this->stack.size() - 1)
		STACK_TO_SMALL_EXCEPTION("stack size < " + value);
	mover = this->stack.top();
	this->stack.pop();
	for (int i = 0; i < (int)number; i++)
	{
		lst.push_front(this->stack.top());
		this->stack.pop();
	}
	this->stack.push(mover);
	for (int i = 0; i < (int)number; i++)
	{
		this->stack.push(lst.front());
		lst.pop_front();
	}
}

void						AbstractVmHandler::handleOperationCopy(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	IOperand const *it = this->stack.top();
	this->stack.push(OperandFactory::Singleton().createOperand(it->getType(), it->toString()));
}

void						AbstractVmHandler::handleOperationInc(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	IOperand const *it = this->stack.top();
	IOperand const *one = OperandFactory::Singleton().createOperand(t_Int8, "1");
	IOperand const *number;
	this->stack.pop();
	number = *it + *one;
	this->stack.push(number);
}

void						AbstractVmHandler::handleOperationDec(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	IOperand const *it = this->stack.top();
	IOperand const *one = OperandFactory::Singleton().createOperand(t_Int8, "1");
	IOperand const *number;
	this->stack.pop();
	number = *it - *one;
	this->stack.push(number);
}

void						AbstractVmHandler::handleOperationPrint(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	IOperand const *it = this->stack.top();

	if (it->getType() != t_Int8)
		NO_PRINTABLE_OPERAND_EXCEPTION("Is not 8bit operand");
	std::cout << (char)std::stoi(it->toString()) << std::endl;
}

void						AbstractVmHandler::handleOperationExit(std::string const & value)
{
	(void)value;
	exit(0);
}

// ###############################################################
