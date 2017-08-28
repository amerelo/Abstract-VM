// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef MOD_CLASS_HPP
# define MOD_CLASS_HPP
# include "Instruction.class.hpp"

class Mod : public Instruction
{
	public:

		Mod( void );
		Mod( Mod const & src );
		virtual ~Mod( void );

		Mod &							operator=( Mod const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Mod const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
