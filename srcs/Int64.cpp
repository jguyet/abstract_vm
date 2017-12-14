#include "AbstractVM.hpp"

// CANONICAL #####################################################

Int64::Int64 ( void )
{
	return ;
}

Int64::Int64 ( Int64 const & src )
{
	*this = src;
	return ;
}

Int64 &						Int64::operator=( Int64 const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Int64::~Int64 ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Int64 const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Int64::operator+( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int64::operator-( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int64::operator*( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int64::operator/( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int64::operator%( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

// ###############################################################

// PUBLIC METHOD #################################################

int 						Int64::getPrecision( void ) const
{
	//64bits = 8 octets
	return (8);
}

eOperandType 				Int64::getType( void ) const
{
	return (t_Int64);
}

std::string const &			Int64::toString( void ) const
{
	return (this->value);
}

// ###############################################################
