
#include "AbstractVM.hpp"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	IOperand const *test;
	IOperand const *test2;
	IOperand const *test3;

	test = OperandFactory::Singleton().createOperand(t_Int8, "8");
	std::cout << test->toString() << std::endl;

	test2 = OperandFactory::Singleton().createOperand(t_Int64, "8");
	std::cout << test2->toString() << std::endl;

	test3 = *test2 / *test;
	std::cout << test3->toString() << std::endl;

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
