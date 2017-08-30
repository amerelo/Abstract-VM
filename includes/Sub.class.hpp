// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef SUB_CLASS_HPP
# define SUB_CLASS_HPP
# include "Instruction.class.hpp"

class Sub : public Instruction
{
	public:
		class NotEnoughElementsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Sub( void );
		Sub( Sub const & src );
		virtual ~Sub( void );

		Sub &							operator=( Sub const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Sub const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
