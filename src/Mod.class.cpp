#include "Mod.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Mod::Mod ( void )
{
	return ;
}

Mod::Mod ( Mod const & src )
{
	*this = src;
	return ;
}

Mod &				Mod::operator=( Mod const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Mod::~Mod ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Mod const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

void Mod::Execute(std::vector<IOperand const *> * stack)
{
	if (stack->size() >= 2)
	{
		IOperand const * tmp1 = *(stack->begin());
		IOperand const * tmp2 = *(stack->begin() + 1);
		stack->erase(stack->begin());
		stack->erase(stack->begin());
		stack->insert(stack->begin(), *tmp2 % *tmp1);
	}
	else
		throw NotEnoughElementsException();
}

// ###############################################################

// GETTER METHOD #################################################

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXCEPTION METHOD ##############################################

const char *Mod::NotEnoughElementsException::what() const throw()
{
		return ("Not Enough Elements in stack");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
