#include "AbstractVM.hpp"

// STATIC ########################################################

OperandFactory OperandFactory::m_instance = OperandFactory();

OperandFactory &		OperandFactory::Singleton( void )
{
	return (m_instance);
}

// ###############################################################

// CANONICAL #####################################################

OperandFactory::OperandFactory ( void )
{
	this->methodsFactory[t_Int8] = &OperandFactory::createInt8;
	this->methodsFactory[t_Int16] = &OperandFactory::createInt16;
	this->methodsFactory[t_Int32] = &OperandFactory::createInt32;
	this->methodsFactory[t_Int64] = &OperandFactory::createInt64;
	this->methodsFactory[t_Float] = &OperandFactory::createFloat;
	this->methodsFactory[t_Double] = &OperandFactory::createDouble;
	return ;
}

OperandFactory::OperandFactory ( OperandFactory const & src )
{
	*this = src;
	return ;
}

OperandFactory &		OperandFactory::operator=( OperandFactory const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

OperandFactory::~OperandFactory ( void )
{
	return ;
}

std::ostream &			operator<<(std::ostream & o, OperandFactory const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

IOperand const * 		OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const	*operand = (this->*methodsFactory[type])(value);
	return (operand);
}

// ###############################################################

// PRIVATE METHOD ################################################

IOperand const * 		OperandFactory::createInt8( std::string const & value ) const
{
	Int8		*operand = new Int8();
	double		number = std::stod(value);

	if (number < std::numeric_limits<char>::min() || number > std::numeric_limits<char>::max())
		LIMIT_EXCEEDED_EXCEPTION("Int8 value: " + value);
	operand->value = value;
	return(operand);
}

IOperand const * 		OperandFactory::createInt16( std::string const & value ) const
{
	Int16		*operand = new Int16();
	double		number = std::stod(value);

	if (number < std::numeric_limits<short>::min() || number > std::numeric_limits<short>::max())
		LIMIT_EXCEEDED_EXCEPTION("Int16 value: " + value);
	operand->value = value;
	return(operand);
}

IOperand const * 		OperandFactory::createInt32( std::string const & value ) const
{
	Int32		*operand = new Int32();
	double		number = std::stod(value);

	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		LIMIT_EXCEEDED_EXCEPTION("Int32 value: " + value);
	operand->value = value;
	return(operand);
}

IOperand const * 		OperandFactory::createInt64( std::string const & value ) const
{
	Int64		*operand = new Int64();
	double		number = std::stod(value);

	if (number < std::numeric_limits<long>::min() || number > std::numeric_limits<long>::max())
		LIMIT_EXCEEDED_EXCEPTION("Int64 value: " + value);
	operand->value = value;
	return(operand);
}


IOperand const * 		OperandFactory::createFloat( std::string const & value ) const
{
	Float		*operand = new Float();
	double		number = std::stod(value);

	if (number < std::numeric_limits<float>::min() || number > std::numeric_limits<float>::max())
		LIMIT_EXCEEDED_EXCEPTION("Float value: " + value);
	operand->value = value;
	return(operand);
}

IOperand const * 		OperandFactory::createDouble( std::string const & value ) const
{
	Double		*operand = new Double();
	double		number = std::stod(value);

	if (number < std::numeric_limits<double>::min() || number > std::numeric_limits<double>::max())
		LIMIT_EXCEEDED_EXCEPTION("Double value: " + value);
	operand->value = value;
	return(operand);
}

// ###############################################################
