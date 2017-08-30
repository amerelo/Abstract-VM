// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef PRINT_CLASS_HPP
# define PRINT_CLASS_HPP
# include "Instruction.class.hpp"

class Print : public Instruction
{
	public:
		class PrintErrorException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		Print( void );
		Print( Print const & src );
		virtual ~Print( void );

		Print &							operator=( Print const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Print const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
