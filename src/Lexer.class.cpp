#include "Lexer.class.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Lexer::Lexer ( void )
{
	return ;
}

Lexer::Lexer ( Lexer const & src )
{
	*this = src;
	return ;
}

Lexer &				Lexer::operator=( Lexer const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Lexer::~Lexer ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &		operator<<(std::ostream & o, Lexer const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################


void Lexer::Instruction_format(std::map<std::string, Instruction *> my_map, std::vector<std::string> tokens)
{
	auto search = my_map.find(*tokens.begin());
	std::regex txt_regex("^((int8|int16|int32|float|double)(\\()(\\+|\\-)?(\\d+)(\\.\\d+)?(\\)))$");

	if (search != my_map.end())
		std::cout << "Valid Ins >>> " << search->first << std::endl;
	else
		std::cout << "Ins Not found" << std::endl;

	for (size_t c_nbr = 1; c_nbr < tokens.size(); c_nbr++)
	{
		if (search != my_map.end() && search->second->needValue() && c_nbr < 2 && !std::regex_match(tokens[c_nbr], txt_regex))
			std::cout << "error " << std::endl;
		else if (search == my_map.end() || (c_nbr >= 2 || !search->second->needValue()))
			std::cout << "command not valid" << std::endl;
	}
}

int Lexer::find_lex_error(std::string line)
{
	static std::map<std::string, Instruction *> my_map =
	{
		std::make_pair("add", new Add), std::make_pair("assert", new Assert),
		std::make_pair("div", new Div), std::make_pair("push", new Push),
		std::make_pair("pop", new Pop), std::make_pair("dump", new Dump),
		std::make_pair("sub", new Sub), std::make_pair("mul", new Mul),
		std::make_pair("mod", new Mod), std::make_pair("print", new Print),
		std::make_pair("exit", new Exit)
	};
	std::istringstream iss(line);
	std::vector<std::string> tokens { std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
	Instruction_format(my_map, tokens);
	return (0);
}

void Lexer::getfile(char *file)
{
	std::string line;
	std::ifstream infile(file);
	std::vector<std::string> myfile;

	while (std::getline(infile, line))
	{
		if (!std::all_of(line.begin(), line.end(), isspace))
		{
			this->rm_comment(&line);
			myfile.push_back(line);
			this->find_lex_error(line);
		}
	}
}

// ###############################################################

// GETTER METHOD #################################################

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

void Lexer::rm_comment(std::string *line)
{
	size_t i = line->find_first_of(";" , 0);
	if (i != std::string::npos)
		line->erase(i);
}

// ###############################################################

// EXCEPTION METHOD ##############################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
