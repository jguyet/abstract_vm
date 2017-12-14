#include "AbstractVM.hpp"

// CANONICAL #####################################################

Double::Double ( void )
{
	return ;
}

Double::Double ( Double const & src )
{
	*this = src;
	return ;
}

Double &						Double::operator=( Double const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Double::~Double ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Double const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Double::operator+( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Double::operator-( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Double::operator*( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Double::operator/( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Double::operator%( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

// ###############################################################

// PUBLIC METHOD #################################################

int 						Double::getPrecision( void ) const
{
	//64 bits = 8 octets
	return (8);
}

eOperandType 				Double::getType( void ) const
{
	return (t_Double);
}

std::string const &			Double::toString( void ) const
{
	return (this->value);
}

// ###############################################################
