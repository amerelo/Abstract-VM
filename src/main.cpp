#include "Lexer.class.hpp"

#include "Factory.class.hpp"
#include "Operation.class.hpp"
#include "Execute.class.hpp"

int main(int ac, char **av)
{
	Factory myFac;
	Lexer lexer = Lexer();
	std::vector<Instruction *> iList;
	int files = 0;

	static std::map<std::string, Instruction *> my_map =
	{
		std::make_pair("add", new Add), std::make_pair("assert", new Assert),
		std::make_pair("div", new Div), std::make_pair("push", new Push),
		std::make_pair("pop", new Pop), std::make_pair("dump", new Dump),
		std::make_pair("sub", new Sub), std::make_pair("mul", new Mul),
		std::make_pair("mod", new Mod), std::make_pair("print", new Print),
		std::make_pair("exit", new Exit), std::make_pair("and", new And),
		std::make_pair("or", new Or), std::make_pair("xor", new Xor)
	};

	while (files < ac)
	{
		try
		{
			if (ac ==  1)
				iList = lexer.getTerminal(my_map);
			else
				iList = lexer.getfile(av[files], my_map);
			Execute exec(iList);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		files++;
	}

	return (0);
}
