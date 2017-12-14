#include "AbstractVM.hpp"

struct zeroNumerator: public std::exception
{
    const char* what() const throw() { return "Numerator can't be 0.\n"; }
};
