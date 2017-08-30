#include "Instruction.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Instruction::Instruction ( void )
{
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
		this->_type = rhs._type;
		this->_value = rhs._value;
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


bool Instruction::needValue()
{
	return (false);
}

void Instruction::getValue(std::string type, std::string value)
{
	if (type == "int8")
		_type = Int8;
	else if (type == "int16")
		_type = Int16;
	else if (type == "int32")
		_type = Int32;
	else if (type == "float")
		_type = Float;
	else if (type == "double")
		_type = Double;

	this->_value = value;
	return ;
}

std::string Instruction::toString()
{
	return (this->_value);
}

void Instruction::Execute(std::vector<IOperand const *> * stack)
{
	(void)stack;
	std::cout << "Instruction" << std::endl;
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
