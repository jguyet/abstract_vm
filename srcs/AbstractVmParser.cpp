#include "AbstractVM.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

AbstractVmParser::AbstractVmParser ( std::string const & cmds )
{
	this->cmds = cmds;
	return ;
}

AbstractVmParser::AbstractVmParser ( void )
{
	this->cmds = "";
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

void							AbstractVmParser::parseCmds( void )
{
	std::vector<std::string> ss = split(this->cmds, '\n');

	for (std::vector<std::string>::iterator it = ss.begin(); it != ss.end(); it++)
	{
		std::vector<std::string> scomments = split(*it, ';');

		if (scomments.size() == 0 || scomments.at(0)[0] == ';')
			continue ;
		std::vector<std::string> ss = split(scomments.at(0), ' ');

		if (ss.size() == 0)
			continue ;
		try
		{
			if (ss.size() > 1)
				AbstractVmHandler::Singleton().handleVmOperation(ss.at(0), ss.at(1));
			else
				AbstractVmHandler::Singleton().handleVmOperation(ss.at(0), "");

		} catch (std::exception &e)
		{
			std::cout << e.what();
			return ;
		}
	}
	NO_EXIT_INSTRUCTION_EXCEPTION("No exit instruction received in program");
}

// ###############################################################
