// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INT16_HPP
# define INT16_HPP

#include "AbstractVM.hpp"

class Int16 : public IOperand
{
	public:

		// Default complaient form #########################
								Int16( void );
								Int16( Int16 const & src );
		virtual					~Int16( void );

		Int16 &					operator=( Int16 const & rhs );
		friend std::ostream &	operator<<(std::ostream & o, Int16 const & i);
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
