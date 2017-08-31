// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef OR_CLASS_HPP
# define OR_CLASS_HPP

# include "Instruction.class.hpp"
# include "Factory.class.hpp"

class Or : public Instruction
{
	public:
		class NotEnoughElementsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Or( void );
		Or( Or const & src );
		virtual ~Or( void );

		Or &							operator=( Or const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Or const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
