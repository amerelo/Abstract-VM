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

Lexer &			Lexer::operator=( Lexer const & rhs )
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

Instruction *Lexer::Instruction_format(std::string line, int nline, std::map<std::string, Instruction *> my_map)
{
	std::smatch match;
	std::istringstream iss(line);
	std::vector<std::string> tokens { std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
	std::vector<std::regex> regexes { std::regex("^(int8|int16|int32|int64|)\\(([\\+|\\-]?\\d+)\\)$"),  std::regex("^(float|double)\\(([\\+|\\-]?\\d+\\.\\d+)\\)$") };

	auto search = my_map.find(*tokens.begin());
	if (search == my_map.end() || (tokens.size() < 2 && search->second->needValue()))
	{
		std::cerr << *tokens.begin() << " command not found in line " << nline << std::endl;
		return (NULL);
	}
	Instruction * instruction(search->second);
	if (search->first == "push")
		instruction = new Push();
	else if (search->first == "assert")
		instruction = new Assert();
	for (size_t c_nbr = 1; c_nbr < tokens.size(); c_nbr++)
	{
		for (size_t i = 0; i < regexes.size() && match.size() == 0; i++)
			std::regex_search(tokens[c_nbr], match, regexes[i]);
		if (c_nbr == 1 && search->second->needValue() && match.size() == 3)
			instruction->getValue(match[1], match[2]);
		else if ((search->second->needValue() && c_nbr < 2 && match.size() != 3) ||
			(c_nbr >= 2 || !search->second->needValue()))
		{
			std::cerr << tokens[c_nbr] << " No Valid Command in line " << nline << std::endl;
			if (search->second->needValue())
				delete instruction;
			return (NULL);
		}
	}
	return (instruction);
}

std::vector<Instruction *> Lexer::getfile(char *file, std::map<std::string, Instruction *> my_map)
{
	int nline = 1;
	int nerror = 0;
	std::string line;
	Instruction *instruction;
	std::ifstream infile(file);
	std::vector<Instruction *> iList;

	while (std::getline(infile, line))
	{
		this->rm_comment(&line);
		if (!std::all_of(line.begin(), line.end(), isspace))
		{
			if ((instruction = this->Instruction_format(line, nline, my_map)) != NULL)
				iList.push_back(instruction);
			else
				nerror++;
		}
		if (nerror > MAX_ERROR)
			throw Lexer::TooManyErrorsException();
		nline++;
	}
	return (iList);
}

std::vector<Instruction *> Lexer::getTerminal(std::map<std::string, Instruction *> my_map)
{
	int nline = 0;
	int nerror = 0;
	std::string line;
	std::vector<Instruction *> iList;
	Instruction * instruction;

	while (std::getline(std::cin, line) && line != ";;")
	{
		if (std::cin.bad() || std::cin.eof())
			return (iList); //trow error
		this->rm_comment(&line);
		if (!std::all_of(line.begin(), line.end(), isspace))
		{
			if ((instruction = this->Instruction_format(line, nline, my_map)))
				iList.push_back(instruction);
			else
				nerror++;
		}
		if (nerror > MAX_ERROR)
			throw Lexer::TooManyErrorsException();
		nline++;
	}
	return (iList);
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

const char *Lexer::TooManyErrorsException::what() const throw()
{
		return ("too many errors in file");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
