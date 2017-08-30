#include "Sub.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Sub::Sub ( void )
{
	return ;
}

Sub::Sub ( Sub const & src )
{
	*this = src;
	return ;
}

Sub &				Sub::operator=( Sub const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Sub::~Sub ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Sub const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

void Sub::Execute(std::vector<IOperand const *> * stack)
{
	if (stack->size() >= 2)
	{
		IOperand const * tmp1 = *(stack->begin());
		IOperand const * tmp2 = *(stack->begin() + 1);
		stack->erase(stack->begin());
		stack->erase(stack->begin());
		stack->insert(stack->begin(), *tmp2 - *tmp1);
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

const char *Sub::NotEnoughElementsException::what() const throw()
{
		return ("Not Enough Elements in stack");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
