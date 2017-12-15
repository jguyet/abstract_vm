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
	this->operationsMethods[VmOperation_add] = &AbstractVmHandler::handleOperationAdd;
	this->operationsMethods[VmOperation_sub] = &AbstractVmHandler::handleOperationSub;
	this->operationsMethods[VmOperation_mul] = &AbstractVmHandler::handleOperationMul;
	this->operationsMethods[VmOperation_div] = &AbstractVmHandler::handleOperationDiv;
	this->operationsMethods[VmOperation_mod] = &AbstractVmHandler::handleOperationMod;
	this->operationsMethods[VmOperation_print] = &AbstractVmHandler::handleOperationPrint;
	this->operationsMethods[VmOperation_exit] = &AbstractVmHandler::handleOperationExit;

	this->operationsMapKey["PUSH"] = VmOperation_push;
	this->operationsMapKey["POP"] = VmOperation_pop;
	this->operationsMapKey["DUMP"] = VmOperation_dump;
	this->operationsMapKey["ASSERT"] = VmOperation_assert;
	this->operationsMapKey["ADD"] = VmOperation_add;
	this->operationsMapKey["SUB"] = VmOperation_sub;
	this->operationsMapKey["MUL"] = VmOperation_mul;
	this->operationsMapKey["DIV"] = VmOperation_div;
	this->operationsMapKey["MOD"] = VmOperation_mod;
	this->operationsMapKey["PRINT"] = VmOperation_print;
	this->operationsMapKey["EXIT"] = VmOperation_exit;
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
	eVmOperationType 	operation_type = this->operationsMapKey.at(upper_cmd);

	(*this.*operationsMethods[operation_type])(value);
}

// ###############################################################

// PRIVATE METHOD ################################################

void						AbstractVmHandler::handleOperationPush(std::string const & value)
{
	this->stack.push_front(OperandFactory::Singleton().createOperand(t_Int8, value));
}

void						AbstractVmHandler::handleOperationPop(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	this->stack.pop_front();
}

void						AbstractVmHandler::handleOperationDump(std::string const & value)
{
	(void)value;
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	for (std::list<IOperand const*>::iterator it = this->stack.begin() ; it != this->stack.end(); ++it)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void						AbstractVmHandler::handleOperationAssert(std::string const & value)
{
	if (this->stack.size() == 0)
		STACK_EMPTY_EXCEPTION("stack size : 0");
	std::list<IOperand const*>::iterator it = this->stack.begin();

	if (value == (*it)->toString())
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
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
	first = *this->stack.begin();
	this->stack.pop_front();
	second = *this->stack.begin();
	this->stack.pop_front();
	result = *first + *second;
	this->stack.push_front(result);
}

void						AbstractVmHandler::handleOperationSub(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = *this->stack.begin();
	this->stack.pop_front();
	second = *this->stack.begin();
	this->stack.pop_front();
	result = *first - *second;
	this->stack.push_front(result);
}

void						AbstractVmHandler::handleOperationMul(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = *this->stack.begin();
	this->stack.pop_front();
	second = *this->stack.begin();
	this->stack.pop_front();
	result = *first * *second;
	this->stack.push_front(result);
}

void						AbstractVmHandler::handleOperationDiv(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = *this->stack.begin();
	this->stack.pop_front();
	second = *this->stack.begin();
	this->stack.pop_front();
	result = *first / *second;
	this->stack.push_front(result);
}

void						AbstractVmHandler::handleOperationMod(std::string const & value)
{
	IOperand const	*result;
	IOperand const	*first;
	IOperand const	*second;

	(void)value;
	if (this->stack.size() < 2)
		STACK_TO_SMALL_EXCEPTION("stack size < 2");
	first = *this->stack.begin();
	this->stack.pop_front();
	second = *this->stack.begin();
	this->stack.pop_front();
	result = *first % *second;
	this->stack.push_front(result);
}

void						AbstractVmHandler::handleOperationPrint(std::string const & value)
{
	(void)value;
}

void						AbstractVmHandler::handleOperationExit(std::string const & value)
{
	(void)value;
	exit(0);
}

// ###############################################################
