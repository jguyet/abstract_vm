#include "AbstractVM.hpp"

// CANONICAL #####################################################

Int8::Int8 ( void )
{
	return ;
}

Int8::Int8 ( Int8 const & src )
{
	*this = src;
	return ;
}

Int8 &				Int8::operator=( Int8 const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Int8::~Int8 ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Int8 const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Int8::operator+( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int8::operator-( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int8::operator*( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int8::operator/( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int8::operator%( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

// ###############################################################

// PUBLIC METHOD #################################################

int 					Int8::getPrecision( void ) const
{
	return (1);
}

eOperandType 			Int8::getType( void ) const
{
	return (t_Int8);
}

std::string const &		Int8::toString( void ) const
{
	return (this->value);
}

// ###############################################################
