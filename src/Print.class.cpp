#include "Print.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Print::Print ( void )
{
	return ;
}

Print::Print ( Print const & src )
{
	*this = src;
	return ;
}

Print &				Print::operator=( Print const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Print::~Print ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Print const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

void Print::Execute(std::vector<IOperand const *> * stack)
{
	IOperand const * first = *((*stack).begin());

	if (first->getType() == 0)
	{
		char printable = std::stoi(first->toString());
		std::cout << printable << std::endl;
	}
	else
		throw PrintErrorException();
}

// ###############################################################

// GETTER METHOD #################################################

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXCEPTION METHOD ##############################################

const char *Print::PrintErrorException::what() const throw()
{
	return ("Print Error");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
