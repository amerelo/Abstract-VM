// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef INSTRUCTION_CLASS_HPP
# define INSTRUCTION_CLASS_HPP
# include <iostream>
# include <stdexcept>

class Instruction
{
	public:

		Instruction( void );
		Instruction( Instruction const & src );
		virtual ~Instruction( void );

		Instruction &						operator=( Instruction const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Instruction const & i);

		virtual bool isvalid(std::string line);
		virtual bool needValue();

	private:
			std::string _name;

};

#endif
