#include "Lexer.class.hpp"
#include "Factory.class.hpp"
#include "Operation.class.hpp"

int main(int ac, char **av)
{
	std::string buff;
	Factory myFac;
	Lexer lexer = Lexer();

	if (ac > 1)
		lexer.getfile(av[1]);
	else
	{
		while (buff != ";;")
		{
			std::getline (std::cin, buff);
			if (std::cin.bad() || std::cin.eof())
				return (0);
		}
	}

	IOperand const * myvector[] = {
		myFac.createOperand(Int8, "5"),
		myFac.createOperand(Int8, "50")
	};

	// std::cout << myvector[0]->toString() << std::endl;
	// std::cout << myvector[0] + myvector[1] ;
	// myvector[0] + myvector[1]


	// Operation<int8_t> const * A = myFac.createOperand(Int8, "5");
	// A + B;

	std::cout << (*myvector[0] - *myvector[1])->toString() << std::endl;

	return (0);
}

// Operation<int32_t> C("-200");
// Operation<float> D("-205.4");
// Operation<double> E("201.69");
