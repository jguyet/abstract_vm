
#include "AbstractVM.hpp"

int		main(int argc, char **argv)
{
	AbstractVmParser	*parser = NULL;
	bool				error_flag = false;

	try
	{
		if (std::string(argv[argc - 1]) == "--force")
		{
			error_flag = true;
			argc--;
		}
		if (argc == 2)
		{
			std::ifstream ifs(argv[1]);
			std::string content;

			if (!ifs)
			{
				FILE_NOT_FOUND_EXCEPTION("File " + std::string(argv[1]) + " not found");
			}
			content.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
			parser = new AbstractVmParser(content, error_flag);
			parser->parseCmds();
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
			parser = new AbstractVmParser(content, error_flag);
			parser->parseCmds();
		}
	} catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
