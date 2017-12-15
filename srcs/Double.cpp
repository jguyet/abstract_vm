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
	o << i.value;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Double::operator+( IOperand const & rhs ) const
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

IOperand const *			Double::operator-( IOperand const & rhs ) const
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

IOperand const *			Double::operator*( IOperand const & rhs ) const
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

IOperand const *			Double::operator/( IOperand const & rhs ) const
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

IOperand const *			Double::operator%( IOperand const & rhs ) const
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
