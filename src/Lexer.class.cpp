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

void Lexer::Value_format(std::vector<std::string> tokens, std::vector<std::string> * myLine, std::map<std::string, Instruction *>::iterator search, std::map<std::string, Instruction *> my_map)
{
	std::smatch match;
	std::regex txt_regex("^(int8|int16|int32|float|double)\\([\\+|\\-]?(\\d+[\\.\\d+]?)\\)$");

	for (size_t c_nbr = 1; c_nbr < tokens.size(); c_nbr++)
	{
		if (search != my_map.end() && c_nbr == 1 && search->second->needValue())
		{
			std::regex_search(tokens[1], match, txt_regex);
			for (size_t i = 1; i < match.size(); i++)
				myLine->push_back(match[i]);
		}
		else if (search != my_map.end() && search->second->needValue() && c_nbr < 2 && !std::regex_match(tokens[c_nbr], txt_regex))
			throw Lexer::BadInstructionException();	//std::cout << "error " << std::endl; // exep
		else if (search == my_map.end() || (c_nbr >= 2 || !search->second->needValue()))
			throw Lexer::NoValidCommandException();
	}
}

std::vector<std::string> Lexer::Instruction_format(std::string line)
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
	std::vector<std::string> myLine;
	std::istringstream iss(line);
	std::vector<std::string> tokens { std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

	auto search = my_map.find(*tokens.begin());
	if (search == my_map.end())
		throw Lexer::BadInstructionException();
	myLine.push_back(search->first); // change
	Value_format(tokens, &myLine, search, my_map);

	return (myLine);
}

std::vector<std::vector<std::string>> Lexer::getfile(char *file)
{
	std::string line;
	std::ifstream infile(file);
	std::vector<std::vector<std::string>> myfile;

	while (std::getline(infile, line))
	{
		if (!std::all_of(line.begin(), line.end(), isspace))
		{
			this->rm_comment(&line);
			try
			{
				myfile.push_back(this->Instruction_format(line));
			}
			catch (std::exception & e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
	return (myfile);
}

std::vector<std::vector<std::string>> Lexer::getTerminal(void)
{
	std::string line;
	std::vector<std::vector<std::string>> myfile;

	while (std::getline (std::cin, line) && line != ";;")
	{
		if (std::cin.bad() || std::cin.eof())
			return (myfile); //trow error
		this->rm_comment(&line);
		try
		{
			myfile.push_back(this->Instruction_format(line));
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (myfile);
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

const char *Lexer::BadInstructionException::what() const throw()
{
		return ("Bad Instruction");
}

const char *Lexer::NoValidCommandException::what() const throw()
{
		return ("No Valid Command");
}

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
