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
	o << i.value;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Float::operator+( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv + rightv;
	strs << result;
	if (this->getPrecision() < rhs.getPrecision())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Float::operator-( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv - rightv;
	strs << result;
	if (this->getPrecision() < rhs.getPrecision())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Float::operator*( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv * rightv;
	strs << result;
	if (this->getPrecision() < rhs.getPrecision())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Float::operator/( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = leftv / rightv;
	strs << result;
	if (this->getPrecision() < rhs.getPrecision())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

IOperand const *			Float::operator%( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = fmod(leftv, rightv);
	strs << result;
	if (this->getPrecision() < rhs.getPrecision())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
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
