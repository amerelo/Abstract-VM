#include "Xor.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Xor::Xor ( void )
{
	return ;
}

Xor::Xor ( Xor const & src )
{
	*this = src;
	return ;
}

Xor &				Xor::operator=( Xor const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Xor::~Xor ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Xor const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

void Xor::Execute(std::vector<IOperand const *> * stack)
{
	if (stack->size() >= 2)
	{
		IOperand const * tmp1 = *(stack->begin());
		IOperand const * tmp2 = *(stack->begin() + 1);
		IOperand const * newop = *tmp2 ^ *tmp1;
		delete tmp1;
		stack->erase((*stack).begin());
		delete tmp2;
		stack->erase((*stack).begin());
		stack->insert(stack->begin(), newop);
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

const char *Xor::NotEnoughElementsException::what() const throw()
{
	return ("Not Enough Elements in stack");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
