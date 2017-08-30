// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef EXECUTE_CLASS_HPP
# define EXECUTE_CLASS_HPP

# include <vector>
# include <map>

# include "IOperand.class.hpp"
# include "Instruction.class.hpp"
# include "instructions.hpp"

class Execute
{
	public:
		class NoExitException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Execute( void );
		Execute(std::vector<Instruction *>  iList);
		Execute( Execute const & src );
		virtual ~Execute( void );

		Execute &							operator=( Execute const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Execute const & i);
};

#endif
