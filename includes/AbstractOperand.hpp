// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef ABSTRACTOPERAND_HPP
# define ABSTRACTOPERAND_HPP

#include "Includes.hpp"

template<class T>
class AbstractOperand : public IOperand
{
	public:

								AbstractOperand( void );
								AbstractOperand( AbstractOperand const & src );
		virtual 				~AbstractOperand( void );

		AbstractOperand<T> &	operator=(AbstractOperand const & rhs );
};

#endif
