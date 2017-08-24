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

		Print( void );
		Print( Print const & src );
		virtual ~Print( void );

		Print &							operator=( Print const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Print const & i);


};

#endif
