#include "AbstractVM.hpp"

// CANONICAL #####################################################

Int32::Int32 ( void )
{
	return ;
}

Int32::Int32 ( Int32 const & src )
{
	*this = src;
	return ;
}

Int32 &						Int32::operator=( Int32 const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Int32::~Int32 ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Int32 const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// OPERATORS #####################################################

IOperand const *			Int32::operator+( IOperand const & rhs ) const
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

IOperand const *			Int32::operator-( IOperand const & rhs ) const
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

IOperand const *			Int32::operator*( IOperand const & rhs ) const
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

IOperand const *			Int32::operator/( IOperand const & rhs ) const
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

IOperand const *			Int32::operator%( IOperand const & rhs ) const
{
	double					rightv = std::stod(rhs.value);
	double					leftv = std::stod(this->value);
	double					result;
	std::ostringstream		strs;
	eOperandType			type = this->getType();

	result = static_cast<long long>(leftv) % static_cast<long long>(rightv);
	strs << result;
	if (type < rhs.getType())
		type = rhs.getType();
	return (OperandFactory::Singleton().createOperand(type, strs.str()));
}

// ###############################################################

// PUBLIC METHOD #################################################

int 						Int32::getPrecision( void ) const
{
	//32bits = 4 octets
	return (4);
}

eOperandType 				Int32::getType( void ) const
{
	return (t_Int32);
}

std::string const &			Int32::toString( void ) const
{
	return (this->value);
}

// ###############################################################
