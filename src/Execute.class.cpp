#include "Execute.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Execute::Execute ( void )
{
	return ;
}

Execute::Execute (std::vector<std::vector<std::string>> myfile)
{
	std::vector<IOperand const *> stack;
	static std::map<std::string, Instruction *> my_map =
	{
		std::make_pair("add", new Add), std::make_pair("assert", new Assert),
		std::make_pair("div", new Div), std::make_pair("push", new Push),
		std::make_pair("pop", new Pop), std::make_pair("dump", new Dump),
		std::make_pair("sub", new Sub), std::make_pair("mul", new Mul),
		std::make_pair("mod", new Mod), std::make_pair("print", new Print),
		std::make_pair("exit", new Exit)
	};

	for(size_t i = 0; i < myfile.size(); i++)
	{
		auto search = my_map.find(myfile[i][0]);
		search->second->Execute(&stack);
	}
	return;
}

Execute::Execute ( Execute const & src )
{
	*this = src;
	return ;
}

Execute &				Execute::operator=( Execute const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Execute::~Execute ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Execute const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

// ###############################################################

// GETTER METHOD #################################################

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXCEPTION METHOD ##############################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
