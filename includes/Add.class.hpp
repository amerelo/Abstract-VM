// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef ADD_CLASS_HPP
# define ADD_CLASS_HPP
# include "Instruction.class.hpp"

class Add : public Instruction
{
	public:
		class NotEnoughElementsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Add(void);
		Add( Add const & src );
		virtual ~Add( void );

		Add &							operator=( Add const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Add const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
