#ifndef OVERFLOW_CLASS_HPP
# define OVERFLOW_CLASS_HPP

# include <string>
# include <type_traits>

template<typename T>
struct Overflow
{
	class OverflownException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Overflow");
		}
	};

	Overflow(long double value, int t)
	{
		if (t == 0)
			IntOverflow(value);
		else if (t == 1)
			DecimalOverflow(value);
		return;
	}


	void IntOverflow(long value)
	{
		if (value < std::numeric_limits<T>::min() || value > std::numeric_limits<T>::max())
			throw OverflownException();
		return;
	}

	void DecimalOverflow(long double value)
	{
		if (value < -std::numeric_limits<T>::max() || value > std::numeric_limits<T>::max())
			throw OverflownException();
	}
};

#endif
