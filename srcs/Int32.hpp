// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INT32_HPP
# define INT32_HPP

#include "AbstractVM.hpp"

class Int32 : public IOperand
{
	public:

		// Default complaient form #########################
								Int32( void );
								Int32( Int32 const & src );
		virtual					~Int32( void );

		Int32 &					operator=( Int32 const & rhs );
		friend std::ostream &	operator<<(std::ostream & o, Int32 const & i);
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
