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

class Lexer
{
	public:
		class BadInstructionException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class NoValidCommandException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		Lexer( void );
		Lexer( Lexer const & src );
		virtual ~Lexer( void );

		Lexer &							operator=( Lexer const & rhs );
		friend std::ostream &			operator<<(std::ostream & o, Lexer const & i);

		void Value_format(std::vector<std::string> tokens, std::vector<std::string> * myLine, std::map<std::string, Instruction *>::iterator search, std::map<std::string, Instruction *> my_map);
		std::vector<std::vector<std::string>> getfile(char * file);
		std::vector<std::vector<std::string>> getTerminal(void);
		std::vector<std::string> Instruction_format(std::string line);

	private:
		void rm_comment(std::string *line);
};

#endif
