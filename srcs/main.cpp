
#include "AbstractVM.hpp"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	try
	{
		AbstractVmHandler::Singleton().handleVmOperation("push", "8");
		AbstractVmHandler::Singleton().handleVmOperation("push", "50");
		AbstractVmHandler::Singleton().handleVmOperation("dump", "");
		AbstractVmHandler::Singleton().handleVmOperation("add", "");
		AbstractVmHandler::Singleton().handleVmOperation("dump", "");
		AbstractVmHandler::Singleton().handleVmOperation("push", "8");
		AbstractVmHandler::Singleton().handleVmOperation("sub", "");
		AbstractVmHandler::Singleton().handleVmOperation("dump", "");
		AbstractVmHandler::Singleton().handleVmOperation("assert", "50");
	} catch (std::exception &e)
	{
		std::cout << e.what();
	}

	return (0);
}
