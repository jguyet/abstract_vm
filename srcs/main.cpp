
#include "AbstractVM.hpp"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	const IOperand *test;

	test = OperandFactory::Singleton().createOperand(t_Int8, "8");
	std::cout << test->toString() << std::endl;
	test = OperandFactory::Singleton().createOperand(t_Int16, "16");
	std::cout << test->toString() << std::endl;
	test = OperandFactory::Singleton().createOperand(t_Int32, "32");
	std::cout << test->toString() << std::endl;
	test = OperandFactory::Singleton().createOperand(t_Int64, "64");
	std::cout << test->toString() << std::endl;
	test = OperandFactory::Singleton().createOperand(t_Float, "float");
	std::cout << test->toString() << std::endl;
	test = OperandFactory::Singleton().createOperand(t_Double, "double");
	std::cout << test->toString() << std::endl;
	return (0);
}
