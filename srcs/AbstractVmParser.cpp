#include "AbstractVM.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

AbstractVmParser::AbstractVmParser ( void )
{
	this->cmds = "";
	this->error_flag = false;
	return ;
}

AbstractVmParser::AbstractVmParser ( std::string const & cmds )
{
	this->cmds = cmds;
	this->error_flag = false;
	return ;
}

AbstractVmParser::AbstractVmParser ( std::string const & cmds, bool const error_flag )
{
	this->cmds = cmds;
	this->error_flag = error_flag;
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
		std::string command = ss.at(0);
		std::string str = scomments.at(0).substr(command.length());

		command.erase(std::remove(std::begin(command), std::end(command), ' '), std::end(command));
		str.erase(std::remove(std::begin(str), std::end(str), ' '), std::end(str));
		try
		{
			AbstractVmHandler::Singleton().handleVmOperation(command, str);
		} catch (std::exception &e)
		{
			std::cout << e.what();
			if (this->error_flag == false)
				return ;
			std::cout << "\033[33m--force enabled the execution of the program continues\033[00m" << std::endl;
		}
	}
	NO_EXIT_INSTRUCTION_EXCEPTION("No exit instruction received in program");
}

// ###############################################################
