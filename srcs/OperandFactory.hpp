// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

#include "AbstractVM.hpp"

class OperandFactory
{
	public:
		// Static Singleton method #########################
		static OperandFactory &	Singleton();
		// #################################################

		// Default complaient form #########################
								OperandFactory( void );
								OperandFactory( OperandFactory const & src );
		virtual 				~OperandFactory( void );

		OperandFactory &		operator=( OperandFactory const & rhs );
		friend std::ostream &	operator<<(std::ostream & o, OperandFactory const & i);
		// #################################################

		// Public methods ##################################
		IOperand const * 		createOperand( eOperandType type, std::string const & value ) const;
		// #################################################
	private:
		// Static Singleton var ############################
		static OperandFactory		m_instance;
		// #################################################

		// Private methods #################################
		IOperand const * 		createInt8( std::string const & value ) const;
		IOperand const * 		createInt16( std::string const & value ) const;
		IOperand const * 		createInt32( std::string const & value ) const;
		IOperand const * 		createFloat( std::string const & value ) const;
		IOperand const * 		createDouble( std::string const & value ) const;
		// #################################################

		// typedef of method pointer #######################
		typedef IOperand const *(OperandFactory::*OperandMethodsFactory)( std::string const & value ) const;
		// #################################################

		// list of methods pointers ########################
		OperandMethodsFactory		methodsFactory[eOperandType_max];
		// #################################################
};

#endif
