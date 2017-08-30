// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef POP_CLASS_HPP
# define POP_CLASS_HPP
# include "Instruction.class.hpp"

class Pop : public Instruction
{
	public:
		class EmptyStackException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Pop( void );
		Pop( Pop const & src );
		virtual ~Pop( void );

		Pop &							operator=( Pop const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Pop const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
