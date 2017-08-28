// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef PUSH_CLASS_HPP
# define PUSH_CLASS_HPP

# include "Instruction.class.hpp"
# include "Factory.class.hpp"

class Push : public Instruction
{
	public:

		Push( void );
		Push( Push const & src );
		virtual ~Push( void );

		Push &							operator=( Push const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Push const & i);

		bool needValue(void);
		void Execute(std::vector<IOperand const *> *stack);

};

#endif
