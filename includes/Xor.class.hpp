// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef XOR_CLASS_HPP
# define XOR_CLASS_HPP

# include "Instruction.class.hpp"
# include "Factory.class.hpp"

class Xor : public Instruction
{
	public:
		class NotEnoughElementsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Xor( void );
		Xor( Xor const & src );
		virtual ~Xor( void );

		Xor &							operator=( Xor const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Xor const & i);

		void Execute(std::vector<IOperand const *> *stack);
};

#endif
