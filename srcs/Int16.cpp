#include "AbstractVM.hpp"

// CANONICAL #####################################################

Int16::Int16 ( void )
{
	return ;
}

Int16::Int16 ( Int16 const & src )
{
	*this = src;
	return ;
}

Int16 &						Int16::operator=( Int16 const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Int16::~Int16 ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Int16 const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Int16::operator+( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int16::operator-( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int16::operator*( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int16::operator/( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

IOperand const *			Int16::operator%( IOperand const & rhs ) const
{
	IOperand				*res;

	res = NULL;
	(void)rhs;

	return (res);
}

// ###############################################################

// PUBLIC METHOD #################################################

int 						Int16::getPrecision( void ) const
{
	//16bits = 2 octets
	return (2);
}

eOperandType 				Int16::getType( void ) const
{
	return (t_Int16);
}

std::string const &			Int16::toString( void ) const
{
	return (this->value);
}

// ###############################################################