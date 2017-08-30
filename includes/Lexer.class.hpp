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
# include <stdexcept>

# include "Instruction.class.hpp"
# include "instructions.hpp"

#define MAX_ERROR 5

class Lexer
{
	public:
		class TooManyErrorsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Lexer( void );
		Lexer( Lexer const & src );
		virtual ~Lexer( void );

		Lexer &							operator=( Lexer const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Lexer const & i);

		std::vector<Instruction *> getfile(char * file, std::map<std::string, Instruction *> my_map);
		std::vector<Instruction *> getTerminal(std::map<std::string, Instruction *> my_map);
		Instruction *Instruction_format(std::string line, int nline, std::map<std::string, Instruction *> my_map);

	private:
		void rm_comment(std::string *line);
};

#endif
