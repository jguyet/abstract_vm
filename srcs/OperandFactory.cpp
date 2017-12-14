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
	this->methodsFactory[t_Float] = &OperandFactory::createFloat;
	this->methodsFactory[t_Double] = &OperandFactory::createDouble;
	return ;
}

OperandFactory::OperandFactory ( OperandFactory const & src )
{
	*this = src;
	return ;
}

OperandFactory &				OperandFactory::operator=( OperandFactory const & rhs )
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

	operand->value = value;
	return(operand);
}

IOperand const * 		OperandFactory::createInt16( std::string const & value ) const
{
	(void)value;
	return (NULL);
}

IOperand const * 		OperandFactory::createInt32( std::string const & value ) const
{
	(void)value;
	return (NULL);
}

IOperand const * 		OperandFactory::createFloat( std::string const & value ) const
{
	(void)value;
	return (NULL);
}

IOperand const * 		OperandFactory::createDouble( std::string const & value ) const
{
	(void)value;
	return (NULL);
}

// ###############################################################
