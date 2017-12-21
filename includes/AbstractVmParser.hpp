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
											AbstractVmParser( void );
											AbstractVmParser( std::string const & cmds );
											AbstractVmParser ( std::string const & cmds, bool const error_flag );
											AbstractVmParser( AbstractVmParser const & src );
		virtual 							~AbstractVmParser( void );

		AbstractVmParser &					operator=( AbstractVmParser const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, AbstractVmParser const & i);
		// #################################################

		// Public methods ##################################
		void								parseCmds( void );
		// #################################################

	private:
		// private vars ####################################
		std::string							cmds;
		bool								error_flag;
		// #################################################
};

#endif
