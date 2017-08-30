// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef DIV_CLASS_HPP
# define DIV_CLASS_HPP
# include "Instruction.class.hpp"

class Div : public Instruction
{
	public:
		class NotEnoughElementsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Div( void );
		Div( Div const & src );
		virtual ~Div( void );

		Div &							operator=( Div const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Div const & i);

		void Execute(std::vector<IOperand const *> *stack);

};

#endif
