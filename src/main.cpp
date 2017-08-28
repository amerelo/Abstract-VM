#include "Lexer.class.hpp"

#include "Factory.class.hpp"
#include "Operation.class.hpp"
#include "Execute.class.hpp"

// class Singleton {
// private:
// 	static Singleton	_;
//
// 	Singleton();
// 	Singleton(const Singleton& rhs) = delete;
// 	Singleton(const Singleton&& rhs) = delete;
// 	const Singleton &operator =(const Singleton& rhs) = delete;
//
// public:
// 	static Singleton *Instance();
//
// };
//
// Singleton::Singleton() {
//  //   whatever
// }
//
// Singleton *Singleton::Instance()
// {
// 	return &_;
// }

// Singleton	Singleton::_;

void init() {
	auto i8 = Operation<int8_t>("0");
	std::cout << i8 + Operation<int8_t>("0");
	std::cout << i8 + Operation<int16_t>("0");
	std::cout << i8 + Operation<int32_t>("0");
	std::cout << i8 + Operation<float>("0");
	std::cout << i8 + Operation<double>("0");

	auto i16 = Operation<int16_t>("0");
	std::cout << i16 + Operation<int8_t>("0");
	std::cout << i16 + Operation<int16_t>("0");
	std::cout << i16 + Operation<int32_t>("0");
	std::cout << i16 + Operation<float>("0");
	std::cout << i16 + Operation<double>("0");

	auto i32 = Operation<int32_t>("0");
	std::cout << i32 + Operation<int8_t>("0");
	std::cout << i32 + Operation<int16_t>("0");
	std::cout << i32 + Operation<int32_t>("0");
	std::cout << i32 + Operation<float>("0");
	std::cout << i32 + Operation<double>("0");

	auto f = Operation<float>("0");
	std::cout << f + Operation<int8_t>("0");
	std::cout << f + Operation<int16_t>("0");
	std::cout << f + Operation<int32_t>("0");
	std::cout << f + Operation<float>("0");
	std::cout << f + Operation<double>("0");

	auto d = Operation<double>("0");
	std::cout << d + Operation<int8_t>("0");
	std::cout << d + Operation<int16_t>("0");
	std::cout << d + Operation<int32_t>("0");
	std::cout << d + Operation<float>("0");
	std::cout << d + Operation<double>("0");

}

int main(int ac, char **av)
{

	Factory myFac;
	Lexer lexer = Lexer();
	std::vector<std::vector<std::string>> myfile;

	try
	{
		myfile = (ac > 1) ? lexer.getfile(av[1]) : lexer.getTerminal();
		Execute exec(myfile);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	size_t i = 0;
	while (i < myfile.size())
	{
		size_t i2 = 0;
		while (i2 < myfile[i].size())
		{
			std::cout << myfile[i][i2] << " ";
			i2++;
		}
		std::cout << std::endl;
		i++;
	}

	return (0);
}

// IOperand const * myvector[] = {
// 	myFac.createOperand(Double, "-7"),
// 	myFac.createOperand(Int8, "-9")
// };
// std::cout << (*myvector[0] - *myvector[1])->toString() << std::endl;
// std::cout << std::numeric_limits<long double>::max() << std::endl;
// Operation<int32_t> C("-200");
// Operation<float> D("-205.4");
// Operation<double> E("201.69");
