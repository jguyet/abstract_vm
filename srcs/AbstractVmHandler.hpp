// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef ABSTRACTVMHANDLER_HPP
# define ABSTRACTVMHANDLER_HPP

#include "AbstractVM.hpp"

class AbstractVmHandler
{
	public:
		// Static Singleton method #########################
		static AbstractVmHandler &		Singleton( void );
		// #################################################

		// Default complaient form #########################
										AbstractVmHandler( void );
										AbstractVmHandler( AbstractVmHandler const & src );
		virtual 						~AbstractVmHandler( void );

		AbstractVmHandler &				operator=( AbstractVmHandler const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, AbstractVmHandler const & i);
		// #################################################

		// Public methods ##################################
		// #################################################
	private:
		// Static Singleton var ############################
		static AbstractVmHandler		m_instance;
		// #################################################
};

#endif
