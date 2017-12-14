#include "AbstractVM.hpp"

// STATIC ########################################################

AbstractVmHandler AbstractVmHandler::m_instance = AbstractVmHandler();

AbstractVmHandler &			AbstractVmHandler::Singleton( void )
{
	return (m_instance);
}

// ###############################################################

// CANONICAL #####################################################

AbstractVmHandler::AbstractVmHandler ( void )
{
	return ;
}

AbstractVmHandler::AbstractVmHandler ( AbstractVmHandler const & src )
{
	*this = src;
	return ;
}

AbstractVmHandler &			AbstractVmHandler::operator=( AbstractVmHandler const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

AbstractVmHandler::~AbstractVmHandler ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, AbstractVmHandler const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

// ###############################################################
