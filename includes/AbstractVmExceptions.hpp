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

// UnknowOperandException ######################################################
struct UnknowOperandException: public std::runtime_error
{
	UnknowOperandException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define UNKNOW_OPERAND_EXCEPTION(aMessage) callUnknowOperandException(aMessage, __func__, __FILE__, __LINE__)

inline void callUnknowOperandException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.UnknowOperandException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw UnknowOperandException(stream.str());
}
// #############################################################################

// SyntaxException #############################################################
struct SyntaxException: public std::runtime_error
{
	SyntaxException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define SYNTAX_EXCEPTION(aMessage) callSyntaxException(aMessage, __func__, __FILE__, __LINE__)

inline void callSyntaxException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.SyntaxException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw SyntaxException(stream.str());
}
// #############################################################################

// NoPrintableOperandException #################################################
struct NoPrintableOperandException: public std::runtime_error
{
	NoPrintableOperandException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define NO_PRINTABLE_OPERAND_EXCEPTION(aMessage) callNoPrintableOperandException(aMessage, __func__, __FILE__, __LINE__)

inline void callNoPrintableOperandException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.NoPrintableOperandException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw NoPrintableOperandException(stream.str());
}
// #############################################################################

// NoExitInstructionException ##################################################
struct NoExitInstructionException: public std::runtime_error
{
	NoExitInstructionException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define NO_EXIT_INSTRUCTION_EXCEPTION(aMessage) callNoExitInstructionException(aMessage, __func__, __FILE__, __LINE__)

inline void callNoExitInstructionException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.NoExitInstructionException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw NoExitInstructionException(stream.str());
}
// #############################################################################

// InvalidAssertOperationException ##################################################
struct InvalidAssertOperationException: public std::runtime_error
{
	InvalidAssertOperationException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define INVALID_ASSERT_EXCEPTION(aMessage) callInvalidAssertOperationException(aMessage, __func__, __FILE__, __LINE__)

inline void callInvalidAssertOperationException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.InvalidAssertOperationException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw InvalidAssertOperationException(stream.str());
}
// #############################################################################

// UnknowVmOperationException ##################################################
struct UnknowVmOperationException: public std::runtime_error
{
	UnknowVmOperationException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define UNKNOW_VM_OPERATION_EXCEPTION(aMessage) callUnknowVmOperationException(aMessage, __func__, __FILE__, __LINE__)

inline void callUnknowVmOperationException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.UnknowVmOperationException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw UnknowVmOperationException(stream.str());
}
// #############################################################################

// FileNotFoundException #######################################################
struct FileNotFoundException: public std::runtime_error
{
	FileNotFoundException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define FILE_NOT_FOUND_EXCEPTION(aMessage) callFileNotFoundException(aMessage, __func__, __FILE__, __LINE__)

inline void callFileNotFoundException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.FileNotFoundException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw FileNotFoundException(stream.str());
}
// #############################################################################

// NumberFormatException #######################################################
struct NumberFormatException: public std::runtime_error
{
	NumberFormatException(const std::string& what_arg) : std::runtime_error(what_arg) {}
};

#define NUMBER_FORMAT_EXCEPTION(aMessage) callNumberFormatException(aMessage, __func__, __FILE__, __LINE__)

inline void callNumberFormatException(const std::string aMessage, const char* funcName, const char* fileName, const std::size_t lineNumber)
{
   std::ostringstream stream;
   stream << ERROR_COLOR << "AbstractVmExceptions.NumberFormatException: " << aMessage << std::endl << "at " << fileName << "(" << funcName << ":" << lineNumber << ")" << RESET_COLOR << std::endl;
   throw NumberFormatException(stream.str());
}
// #############################################################################
