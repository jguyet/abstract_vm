// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef FLOAT_HPP
# define FLOAT_HPP

#include "AbstractVM.hpp"

class Float : public IOperand
{
	public:

		// Default complaient form #########################
								Float( void );
								Float( Float const & src );
		virtual					~Float( void );

		Float &					operator=( Float const & rhs );
		friend std::ostream &	operator<<(std::ostream & o, Float const & i);
		// #################################################

		// Public methods ##################################
		int 					getPrecision( void ) const;							// Precision of the type of the instance
		eOperandType 			getType( void ) const;								// Type of the instance
		IOperand const *		operator+( IOperand const & rhs ) const;			// Sum
		IOperand const *		operator-( IOperand const & rhs ) const;			// Difference
		IOperand const *		operator*( IOperand const & rhs ) const;			// Product
		IOperand const *		operator/( IOperand const & rhs ) const;			// Quotient
		IOperand const *		operator%( IOperand const & rhs ) const;			// Modulo
		std::string const &		toString( void ) const;			 					// String representation of the instance
		// #################################################
};

#endif
