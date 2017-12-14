
#include "AbstractVM.hpp"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	const IOperand *test = OperandFactory::Singleton().createOperand(t_Int8, "50");

	std::cout << test->toString() << std::endl;
	return (0);
}
