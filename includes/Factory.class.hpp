// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP
# include "IOperand.class.hpp"

class Factory
{
	public:

		Factory( void );
		Factory( Factory const & src );
		virtual ~Factory( void );

		Factory &							operator=( Factory const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Factory const & i);

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createInt64( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

typedef IOperand const * (Factory::*Create)(std::string const &) const;

#endif
