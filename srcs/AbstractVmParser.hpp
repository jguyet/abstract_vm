// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef ABSTRACTVMPARSER_HPP
# define ABSTRACTVMPARSER_HPP

#include "AbstractVM.hpp"

class AbstractVmParser
{
	public:
		// Default complaient form #########################
											AbstractVmParser( std::string const & cmds );
											AbstractVmParser( void );
											AbstractVmParser( AbstractVmParser const & src );
		virtual 							~AbstractVmParser( void );

		AbstractVmParser &					operator=( AbstractVmParser const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, AbstractVmParser const & i);
		// #################################################
	private:
		//std::string const &					cmds;
};

#endif
