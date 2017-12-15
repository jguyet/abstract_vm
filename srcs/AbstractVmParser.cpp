#include "AbstractVM.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

AbstractVmParser::AbstractVmParser ( std::string const & cmds )
{
	(void)cmds;
	//this->cmds = cmds;
	return ;
}

AbstractVmParser::AbstractVmParser ( void )
{
	//this->cmds = std::string("");
	return ;
}

AbstractVmParser::AbstractVmParser ( AbstractVmParser const & src )
{
	*this = src;
	return ;
}

AbstractVmParser &				AbstractVmParser::operator=( AbstractVmParser const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

AbstractVmParser::~AbstractVmParser ( void )
{
	return ;
}

std::ostream &					operator<<(std::ostream & o, AbstractVmParser const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

// ###############################################################
