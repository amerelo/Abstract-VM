#include "Lexer.class.hpp"

#include "Factory.class.hpp"
#include "Operation.class.hpp"
#include "Execute.class.hpp"

// class Singleton {
// private:
// 	static Singleton	_;
//
// 	Singleton();
// 	Singleton(const Singleton& rhs) = delete;
// 	Singleton(const Singleton&& rhs) = delete;
// 	const Singleton &operator =(const Singleton& rhs) = delete;
//
// public:
// 	static Singleton *Instance();
//
// };
//
// Singleton::Singleton() {
//  //   whatever
// }
//
// Singleton *Singleton::Instance()
// {
// 	return &_;
// }
// Singleton	Singleton::_;

int main(int ac, char **av)
{
	Factory myFac;
	Lexer lexer = Lexer();
	std::vector<Instruction *> iList;
	static std::map<std::string, Instruction *> my_map =
	{
		std::make_pair("add", new Add), std::make_pair("assert", new Assert),
		std::make_pair("div", new Div), std::make_pair("push", new Push),
		std::make_pair("pop", new Pop), std::make_pair("dump", new Dump),
		std::make_pair("sub", new Sub), std::make_pair("mul", new Mul),
		std::make_pair("mod", new Mod), std::make_pair("print", new Print),
		std::make_pair("exit", new Exit)
	};
	try
	{
		iList = (ac > 1) ? lexer.getfile(av[1], my_map) : lexer.getTerminal(my_map);
		Execute exec(iList);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
