#include "Mul.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Mul::Mul ( void )
{
	return ;
}

Mul::Mul ( Mul const & src )
{
	*this = src;
	return ;
}

Mul &				Mul::operator=( Mul const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Mul::~Mul ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Mul const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

void Mul::Execute(std::vector<IOperand const *> * stack)
{
	if (stack->size() >= 2)
	{
		IOperand const * tmp1 = *(stack->begin());
		IOperand const * tmp2 = *(stack->begin() + 1);
		stack->erase(stack->begin());
		stack->erase(stack->begin());
		stack->insert(stack->begin(), *tmp2 * *tmp1);
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

const char *Mul::NotEnoughElementsException::what() const throw()
{
		return ("Not Enough Elements in stack");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
