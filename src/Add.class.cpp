#include "Add.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Add::Add ( void )
{
	return ;
}

Add::Add ( Add const & src )
{
	*this = src;
	return ;
}

Add &			Add::operator=( Add const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Add::~Add ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &		operator<<(std::ostream & o, Add const & i)
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
