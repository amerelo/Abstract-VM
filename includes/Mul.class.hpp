// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef MUL_CLASS_HPP
# define MUL_CLASS_HPP
# include "Instruction.class.hpp"

class Mul : public Instruction
{
	public:

		Mul( void );
		Mul( Mul const & src );
		virtual ~Mul( void );

		Mul &							operator=( Mul const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Mul const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
