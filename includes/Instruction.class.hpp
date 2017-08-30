// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INSTRUCTION_CLASS_HPP
# define INSTRUCTION_CLASS_HPP
# include <iostream>
# include <stdexcept>
# include <vector>

# include "Operation.class.hpp"
# include "IOperand.class.hpp"


class Instruction
{
	public:

		Instruction( void );
		Instruction( Instruction const & src );
		virtual ~Instruction( void );

		Instruction &						operator=( Instruction const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Instruction const & i);

		virtual bool needValue();
		virtual void getValue(std::string type, std::string value);
		virtual void Execute(std::vector<IOperand const *> *stack);
		virtual std::string toString();

	protected:
		eOperandType _type;
		std::string _value;
};

#endif
