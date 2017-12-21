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
		void							handleVmOperation(std::string const & cmd, std::string const & value);
		// #################################################
	private:
		// Static Singleton var ############################
		static AbstractVmHandler		m_instance;
		// #################################################

		// Private methods #################################
		void							handleOperationPush(std::string const & value);
		void							handleOperationPop(std::string const & value);
		void							handleOperationDump(std::string const & value);
		void							handleOperationAssert(std::string const & value);
		void							handleOperationAdd(std::string const & value);
		void							handleOperationSub(std::string const & value);
		void							handleOperationMul(std::string const & value);
		void							handleOperationDiv(std::string const & value);
		void							handleOperationMod(std::string const & value);
		void							handleOperationPrint(std::string const & value);
		void							handleOperationExit(std::string const & value);
		void							handleOperationMov(std::string const & value);
		void							handleOperationCopy(std::string const & value);
		void							handleOperationInc(std::string const & value);
		void							handleOperationDec(std::string const & value);
		// #################################################

		// typedef of methods handler pointers #############
		typedef void (AbstractVmHandler::*VmOperationMethods)( std::string const & value );
		// #################################################

		// list of methods handler pointers ################
		VmOperationMethods							operationsMethods[eVmOperationType_max];
		// #################################################

		// private vars ####################################
		std::map<std::string, eVmOperationType>		operationsMapKey;
		std::map<std::string, eOperandType>			pushOperationsMapKey;
		std::stack<IOperand const*>					stack;
		// #################################################
};

#endif
