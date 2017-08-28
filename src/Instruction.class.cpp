#include "Instruction.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Instruction::Instruction ( void )
{
	this->_name = "instruction";
	return ;
}

Instruction::Instruction ( Instruction const & src )
{
	*this = src;
	return ;
}

Instruction &				Instruction::operator=( Instruction const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Instruction::~Instruction ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Instruction const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

bool Instruction::isvalid(std::string line)
{
	if (line != "toto")
		std::cout << "Valide" << std::endl;

	return (true);
}

bool Instruction::needValue()
{
	return (false);
}

void Instruction::Execute(std::vector<IOperand const *> * stack)
{
	Factory fac;

	stack->insert(stack->begin(), fac.createOperand(Int8, "85"));
}

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
