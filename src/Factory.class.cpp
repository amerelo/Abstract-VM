#include "Factory.class.hpp"
#include "Operation.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Factory::Factory ( void )
{
	return ;
}

Factory::Factory ( Factory const & src )
{
	*this = src;
	return ;
}

Factory &				Factory::operator=( Factory const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Factory::~Factory ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Factory const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################


IOperand const * Factory::createInt8( std::string const & value ) const
{
	return (new Operation<int8_t>(value));
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
	return (new Operation<int16_t>(value));
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
	return (new Operation<int32_t>(value));
}

IOperand const * Factory::createInt64( std::string const & value ) const
{
	return (new Operation<int64_t>(value));
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
	return (new Operation<float>(value));
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
	return (new Operation<double>(value));
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	static Create fac[6] =
	{
		&Factory::createInt8, &Factory::createInt16, &Factory::createInt32,
		&Factory::createInt64, &Factory::createFloat, &Factory::createDouble
	};
	return ((this->*fac[type])(value));
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
