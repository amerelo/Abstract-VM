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

private:
	// T	_value;

public:
	// class IOperationException : public std::exception {
	//
	// }
	//
	// template<T>class OperationException : public IOperationException {
	//
	// }

	// class BadInstructionException : public std::exception
	// {
	// public:
	// 	virtual const char *what() const throw
	// 	{
	// 		return ("No Valid Command");
	// 	}
	// };

	Operation ( void ) : _value("0"), _type(Int8)
	{
		this->cast();
		return ;
	}

	Operation ( std::string value ) : _value(value)
	{
		if (std::is_same<T, int8_t>::value)
			this->_type = Int8;
		else if (std::is_same<T, int8_t>::value)
			this->_type = Int16;
		else if (std::is_same<T, int32_t>::value)
			this->_type = Int32;
		else if (std::is_same<T, float>::value)
			this->_type = Float;
		else if (std::is_same<T, double>::value)
			this->_type = Double;
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

		if (p < 3)
		{
			long value = 0;
			value = std::stoi(this->toString()) + std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value);
			else if (p == Int16)
				Overflow<int16_t> test(value);
			else if (p == Int32)
				Overflow<int32_t> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) + std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value);
			else if (p == Double)
				Overflow<double> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator-( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 3)
		{
			long value = 0;
			value = std::stoi(this->toString()) - std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value);
			else if (p == Int16)
				Overflow<int16_t> test(value);
			else if (p == Int32)
				Overflow<int32_t> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) - std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value);
			else if (p == Double)
				Overflow<double> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator*( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 3)
		{
			long value = 0;
			value = std::stoi(this->toString()) * std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value);
			else if (p == Int16)
				Overflow<int16_t> test(value);
			else if (p == Int32)
				Overflow<int32_t> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) * std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value);
			else if (p == Double)
				Overflow<double> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator/( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (std::stod(rhs.toString()) == 0)
		{
			std::cout << "error / 0 " << std::endl;
			return (NULL);
		}

		if (p < 3)
		{
			long value = 0;
			value = std::stoi(this->toString()) / std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value);
			else if (p == Int16)
				Overflow<int16_t> test(value);
			else if (p == Int32)
				Overflow<int32_t> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			double value = 0;
			value =  std::stod(this->toString()) / std::stod(rhs.toString());
			if (p == Float)
				Overflow<float> test(value);
			else if (p == Double)
				Overflow<double> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
	}

	IOperand const * operator%( IOperand const & rhs ) const
	{
		Factory fac;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (p < 3)
		{
			long value = 0;
			value = std::stoi(this->toString()) * std::stoi(rhs.toString());
			if ( p == Int8)
				Overflow<int8_t> test(value);
			else if (p == Int16)
				Overflow<int16_t> test(value);
			else if (p == Int32)
				Overflow<int32_t> test(value);
			return (fac.createOperand(p, std::to_string(value)));
		}
		else
		{
			// float
			std::cout << "error" << std::endl;
			// double
			std::cout << "error" << std::endl;
			return (NULL);
		}
	}

private:
	std::string _value;
	eOperandType _type;
};

#endif
