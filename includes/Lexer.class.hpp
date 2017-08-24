// ------------------------------------------------------------	//
//					general includes 							//
//							for lexer/parser					//
// ------------------------------------------------------------	//

#ifndef LEXER_CLASS_HPP
# define LEXER_CLASS_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include <vector>
# include <map>
# include <utility>
# include <sstream>
# include <functional>
# include <regex>

# include "Instruction.class.hpp"
# include "instructions.hpp"

class Lexer
{
	public:

		Lexer( void );
		Lexer( Lexer const & src );
		virtual ~Lexer( void );

		Lexer &							operator=( Lexer const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Lexer const & i);

		void getfile(char * file);
		int find_lex_error(std::string line);
		void Instruction_format(std::map<std::string, Instruction *> my_map, std::vector<std::string> tokens);

	private:
		void rm_comment(std::string *line);
};

#endif
