// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INT8_HPP
# define INT8_HPP

#include "Includes.hpp"

#include "AbstractOperand.hpp"

using std::ostream;

class Int8 : public AbstractOperand<class Int8>
{
	public:

		Int8( void );
		Int8( Int8 const & src );
		virtual ~Int8( void );

		Int8 &							operator=( Int8 const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Int8 const & i);


};

#endif
