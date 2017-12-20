
#include "AbstractVM.hpp"

int		main(int argc, char **argv)
{
	AbstractVmParser	*parser = NULL;

	try
	{
		if (argc == 2)
		{
			std::ifstream ifs(argv[1]);
			std::string content;

			if (!ifs)
			{
				//Exception file
			}
			content.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
			parser = new AbstractVmParser(content);
		}
		else
		{
			std::string content;

			for (std::string line; std::getline(std::cin, line);)
			{
				if (line == ";;")
					break ;
				content += line + "\n";
		    }
			parser = new AbstractVmParser(content);
		}
		parser->parseCmds();
	} catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
