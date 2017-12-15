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

Int8 &						Int8::operator=( Int8 const & rhs )
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
	o << i.value;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Int8::operator+( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv + rightv;
	strs << result;
	if (type < rhs.getType())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Int8::operator-( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv - rightv;
	strs << result;
	if (type < rhs.getType())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Int8::operator*( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv * rightv;
	strs << result;
	if (type < rhs.getType())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Int8::operator/( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv / rightv;
	strs << result;
	if (type < rhs.getType())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Int8::operator%( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = fmod(leftv, rightv);
	strs << result;
	if (type < rhs.getType())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

// ###############################################################

// PUBLIC METHOD #################################################

int 						Int8::getPrecision( void ) const
{
	//8bits = 1 octet
	return (1);
}

eOperandType 				Int8::getType( void ) const
{
	return (t_Int8);
}

std::string const &			Int8::toString( void ) const
{
	return (this->value);
}

// ###############################################################
