// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef DUMP_CLASS_HPP
# define DUMP_CLASS_HPP
# include "Instruction.class.hpp"

class Dump : public Instruction
{
	public:
		Dump( void );
		Dump( Dump const & src );
		virtual ~Dump( void );

		Dump &							operator=( Dump const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Dump const & i);

		void Execute(std::vector<IOperand const *> *stack);

};

#endif
