#include "Execute.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Execute::Execute ( void )
{
	return ;
}

Execute::Execute (std::vector<Instruction *> iList)
{
	std::vector<IOperand const *> stack;

	try
	{
		for(size_t i = 0; i < iList.size(); i++)
			iList[i]->Execute(&stack);
	}
	catch (Exit::ExitException & e)
	{
		this->DeleteV (&stack, &iList);
		return ;
	}
	this->DeleteV (&stack, &iList);
	throw Execute::NoExitException();
	return ;
}

Execute::Execute ( Execute const & src )
{
	*this = src;
	return ;
}

Execute &		Execute::operator=( Execute const & rhs )
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

void Execute::DeleteV (std::vector<IOperand const *> *stack, std::vector<Instruction *> *iList)
{
	for (size_t z = 0; z < (*stack).size(); z++)
		delete (*stack)[z];
	for(size_t i = 0; i < (*iList).size(); i++)
	{
		if ((*iList)[i]->needValue())
			delete (*iList)[i];
	}
}

// ###############################################################

// EXCEPTION METHOD ##############################################

const char *Execute::NoExitException::what() const throw()
{
	return ("No Exit command found");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
