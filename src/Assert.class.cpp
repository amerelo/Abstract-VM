#include "Assert.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Assert::Assert ( void )
{
	return ;
}

Assert::Assert ( Assert const & src )
{
	*this = src;
	return ;
}

Assert &				Assert::operator=( Assert const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Assert::~Assert ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Assert const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

bool Assert::needValue()
{
	return (true);
}

void Assert::Execute(std::vector<IOperand const *> * stack)
{
	IOperand const * first = *((*stack).begin());

	if (first->toString() == this->_value)
		std::cout << "Assert OK for value " << this->_value << std::endl;
	else
		throw AssertErrorsException();
}

// ###############################################################

// GETTER METHOD #################################################

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXCEPTION METHOD ##############################################

const char *Assert::AssertErrorsException::what() const throw()
{
		return ("Assert Error");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
