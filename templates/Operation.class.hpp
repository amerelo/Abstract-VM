#ifndef OPERATION_CLASS_HPP
# define OPERATION_CLASS_HPP

# include <string>
# include <type_traits>

# include "Factory.class.hpp"
# include "IOperand.class.hpp"
# include "Overflow.class.hpp"

template<typename T>
class Operation : public IOperand
{

public:
	class ZeroDivisionException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("division by 0");
		}
	};

	class ModErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("No Modulo for decimal numbers");
		}
	};

	class AndErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("No And for decimal numbers");
		}
	};

	class OrErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("No Or for decimal numbers");
		}
	};

	class XorErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("No Xor for decimal numbers");
		}
	};

	Operation ( void ) : _value("0"), _type(Int8)
	{
		this->cast();
		return ;
	}

	Operation ( std::string value ) : _value(value)
	{
		double myvalue = std::stod(value);

		if (std::is_same<T, int8_t>::value)
		{
			this->_type = Int8;
			myvalue = static_cast<long>(myvalue);
			Overflow<int8_t> test(myvalue, 0);
		}
		else if (std::is_same<T, int16_t>::value)
		{
			this->_type = Int16;
			myvalue = static_cast<long>(myvalue);
			Overflow<int16_t> test(myvalue, 0);
		}
		else if (std::is_same<T, int32_t>::value)
		{
			this->_type = Int32;
			myvalue = static_cast<long>(myvalue);
			Overflow<int32_t> test(myvalue, 0);
		}
		else if (std::is_same<T, int64_t>::value)
		{
			this->_type = Int64;
			myvalue = static_cast<long>(myvalue);
			Overflow<int64_t> test(myvalue, 0);
		}
		else if (std::is_same<T, float>::value)
		{
			this->_type = Float;
			Overflow<float> test(myvalue, 1);
		}
		else if (std::is_same<T, double>::value)
		{
			this->_type = Double;
			Overflow<double> test(myvalue, 1);
		}

		return ;
	}

	~Operation( void )
	{
		return ;
	}

	Operation ( Operation const & src )
	{
		*this = src;
		return ;
	}

	Operation &	operator=( Operation const & rhs )
	{
		if (this != &rhs)
		{
			this->_value = rhs._value;
			this->_type = rhs._type;
		}
		return (*this);
	}

	friend std::ostream & operator<<(std::ostream & o, Operation const & i)
	{
		(void)i;
		return (o);
	}

	int getPrecision( void ) const
	{
		return (this->_type);
	}

	eOperandType getType( void ) const
	{
		return (this->_type);
	}

	std::string const & toString( void ) const
	{
		return this->_value;
	}

	IOperand const * cast(void)
	{
		return this;
	}

	IOperand const * operator+( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();
		if (p < 4)
		{
			long value = std::stoi(this->toString()) + std::stoi(rhs.toString());

			if (p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value =  std::stod(this->toString()) + std::stod(rhs.toString());

			if (p == Float)
				Overflow<float> test(value, 1);
			else if (p == Double)
				Overflow<double> test(value, 1);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator-( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) - std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) - std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value, 1);
			else if (p == Double)
				Overflow<double> test(value, 1);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator*( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) * std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) * std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value, 1);
			else if (p == Double)
				Overflow<double> test(value, 1);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator/( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (std::stod(rhs.toString()) == 0)
			throw Operation::ZeroDivisionException();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) / std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) / std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value, 1);
			else if (p == Double)
				Overflow<double> test(value, 1);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator%( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (std::stod(rhs.toString()) == 0)
			throw Operation::ZeroDivisionException();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) * std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
			throw Operation::ModErrorException();
	}

	IOperand const * operator&( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) & std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
			throw Operation::AndErrorException();
	}

	IOperand const * operator|( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) | std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
			throw Operation::OrErrorException();
	}

	IOperand const * operator^( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 4)
		{
			long value = 0;
			value = std::stoi(this->toString()) ^ std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value, 0);
			else if (p == Int16)
				Overflow<int16_t> test(value, 0);
			else if (p == Int32)
				Overflow<int32_t> test(value, 0);
			else if (p == Int64)
				Overflow<int64_t> test(value, 0);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
			throw Operation::XorErrorException();
	}

private:
	std::string _value;
	eOperandType _type;
};

#endif
