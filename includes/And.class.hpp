// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef AND_CLASS_HPP
# define AND_CLASS_HPP

# include "Instruction.class.hpp"
# include "Factory.class.hpp"

class And : public Instruction
{
	public:
		class NotEnoughElementsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		And( void );
		And( And const & src );
		virtual ~And( void );

		And &							operator=( And const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, And const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
