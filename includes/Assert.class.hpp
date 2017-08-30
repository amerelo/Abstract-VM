// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef ASSERT_CLASS_HPP
# define ASSERT_CLASS_HPP
# include "Instruction.class.hpp"

class Assert : public Instruction
{
	public:
		class AssertErrorsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		
		Assert(void);
		Assert( Assert const & src );
		virtual ~Assert( void );

		Assert &							operator=( Assert const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Assert const & i);

		bool needValue();
		void Execute(std::vector<IOperand const *> *stack);
};

#endif
