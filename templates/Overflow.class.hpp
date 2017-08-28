#ifndef OVERFLOW_CLASS_HPP
# define OVERFLOW_CLASS_HPP

# include <string>
# include <type_traits>

template<typename T>
struct Overflow
{
	Overflow(long double value)
	{
		if (value < std::numeric_limits<T>::min() || value > std::numeric_limits<T>::max())
			std::cout << "Error" << std::endl;
		else
			std::cout << "value OK > " << value << std::endl;
		return;
	}
};

#endif
