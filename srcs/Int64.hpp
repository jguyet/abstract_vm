// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INT64_HPP
# define INT64_HPP

#include "AbstractVM.hpp"

class Int64 : public IOperand
{
	public:

		// Default complaient form #########################
								Int64( void );
								Int64( Int64 const & src );
		virtual					~Int64( void );

		Int64 &					operator=( Int64 const & rhs );
		friend std::ostream &	operator<<(std::ostream & o, Int64 const & i);
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
