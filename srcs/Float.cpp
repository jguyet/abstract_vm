#include "AbstractVM.hpp"

// CANONICAL #####################################################

Float::Float ( void )
{
	return ;
}

Float::Float ( Float const & src )
{
	*this = src;
	return ;
}

Float &						Float::operator=( Float const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Float::~Float ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Float const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Float::operator+( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Float::operator-( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Float::operator*( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Float::operator/( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Float::operator%( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

// ###############################################################

// PUBLIC METHOD #################################################

int 						Float::getPrecision( void ) const
{
	//32 bits = 4 octets
	return (4);
}

eOperandType 				Float::getType( void ) const
{
	return (t_Float);
}

std::string const &			Float::toString( void ) const
{
	return (this->value);
}

// ###############################################################
