#include "AbstractVM.hpp"

#define ERROR_COLOR "\033[31m"
#define RESET_COLOR "\033[00m"



// StackEmptyException #########################################################
struct StackEmptyException: public std::runtime_error
{
	StackEmptyException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define STACK_EMPTY_EXCEPTION(aMessage) callStackEmptyException(aMessage, __func__, __FILE__, __LINE__)

inline void callStackEmptyException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.StackEmptyException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw StackEmptyException(stream.str());
}
// #############################################################################

// StackToSmallException #######################################################
struct StackToSmallException: public std::runtime_error
{
	StackToSmallException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define STACK_TO_SMALL_EXCEPTION(aMessage) callStackToSmallException(aMessage, __func__, __FILE__, __LINE__)

inline void callStackToSmallException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.StackToSmallException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw StackToSmallException(stream.str());
}
// #############################################################################

// LimitExceededException ######################################################
struct LimitExceededException: public std::runtime_error
{
	LimitExceededException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define LIMIT_EXCEEDED_EXCEPTION(aMessage) callLimitExceededException(aMessage, __func__, __FILE__, __LINE__)

inline void callLimitExceededException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.LimitExceededException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw LimitExceededException(stream.str());
}
// #############################################################################
