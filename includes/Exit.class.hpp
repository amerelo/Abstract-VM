// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef EXIT_CLASS_HPP
# define EXIT_CLASS_HPP
# include "Instruction.class.hpp"

class Exit : public Instruction
{
	public:

		Exit( void );
		Exit( Exit const & src );
		virtual ~Exit( void );

		Exit &							operator=( Exit const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Exit const & i);

		void Execute(std::vector<IOperand const *> *stack);

};

#endif
