// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INT8_HPP
# define INT8_HPP

#include "AbstractVM.hpp"

class Int8 : public IOperand
{
	public:

		// Default complaient form #########################
								Int8( void );
								Int8( Int8 const & src );
		virtual					~Int8( void );

		Int8 &					operator=( Int8 const & rhs );
		friend std::ostream &	operator<<(std::ostream & o, Int8 const & i);
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
