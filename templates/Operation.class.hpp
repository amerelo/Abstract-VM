#ifndef OPERATION_CLASS_HPP
# define OPERATION_CLASS_HPP

#include <string>
#include <type_traits>
#include "Factory.class.hpp"
#include "IOperand.class.hpp"
#include "Overflow.class.hpp"

template<typename T>
class Operation : public IOperand
{

public:
	Operation ( void ) : _value("0"), _type(Int8)
	{
		return ;
	}

	Operation ( std::string value ) : _value(value)
	{
		//check Overflow
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
			this->_value = rhs->_value;
			this->_type = rhs->_type;
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
		return(this->_value);
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
		double value = 0;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		switch(p)
		{
			case Int8 : {
				value = std::stoi(this->toString()) - std::stoi(rhs.toString());
				if (value < std::numeric_limits<int8_t>::min() || value > std::numeric_limits<int8_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int16 :
			{
				value = std::stoi(this->toString()) - std::stoi(rhs.toString());
				if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int32 :
			{
				value = std::stoi(this->toString())  - std::stoi(rhs.toString());
				if (value < std::numeric_limits<int32_t>::min() || value > std::numeric_limits<int32_t>::max())
					std::cout << "Overflow";
				break;
			}
			case Float :
			{
				value =  std::stod(this->toString()) - std::stod(rhs.toString());
				if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
					std::cout << "Overflow";
				break;
			}
			case Double :
			{
				value =  std::stod(this->toString()) - std::stod(rhs.toString());
				if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
		}
		return (fac.createOperand(p, std::to_string(value)));
	}

	IOperand const * operator*( IOperand const & rhs ) const
	{
		Factory fac;
		double value = 0;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		switch(p)
		{
			case Int8 : {
				value = std::stoi(this->toString()) * std::stoi(rhs.toString());
				if (value < std::numeric_limits<int8_t>::min() || value > std::numeric_limits<int8_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int16 :
			{
				value = std::stoi(this->toString()) * std::stoi(rhs.toString());
				if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int32 :
			{
				value = std::stoi(this->toString()) * std::stoi(rhs.toString());
				if (value < std::numeric_limits<int32_t>::min() || value > std::numeric_limits<int32_t>::max())
					std::cout << "Overflow";
				break;
			}
			case Float :
			{
				value = std::stod(this->toString()) * std::stod(rhs.toString());
				if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
					std::cout << "Overflow";
				break;
			}
			case Double :
			{
				value = std::stod(this->toString()) * std::stod(rhs.toString());
				if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
		}
		return (fac.createOperand(p, std::to_string(value)));
	}

	IOperand const * operator/( IOperand const & rhs ) const
	{
		Factory fac;
		double value = 0;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();

		if (std::stod(rhs.toString()) == 0)
		{
			std::cout << "error / 0 " << std::endl;
			return (NULL);
		}

		switch(p)
		{
			case Int8 : {
				value = std::stoi(this->toString()) / std::stoi(rhs.toString());
				if (value < std::numeric_limits<int8_t>::min() || value > std::numeric_limits<int8_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int16 :
			{
				value = std::stoi(this->toString()) / std::stoi(rhs.toString());
				if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int32 :
			{
				value = std::stoi(this->toString()) / std::stoi(rhs.toString());
				if (value < std::numeric_limits<int32_t>::min() || value > std::numeric_limits<int32_t>::max())
					std::cout << "Overflow";
				break;
			}
			case Float :
			{
				value = std::stod(this->toString()) / std::stod(rhs.toString());
				if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
					std::cout << "Overflow";
				break;
			}
			case Double :
			{
				value = std::stod(this->toString()) / std::stod(rhs.toString());
				if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
		}
		return (fac.createOperand(p, std::to_string(value)));
	}

	IOperand const * operator%( IOperand const & rhs ) const
	{
		Factory fac;
		double value = 0;
		eOperandType p = (this->getPrecision() > rhs.getPrecision()) ? this->getType() : rhs.getType();


		switch(p)
		{
			case Int8 : {
				value = std::stoi(this->toString()) % std::stoi(rhs.toString());
				if (value < std::numeric_limits<int8_t>::min() || value > std::numeric_limits<int8_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int16 :
			{
				value = std::stoi(this->toString()) % std::stoi(rhs.toString());
				if (value < std::numeric_limits<int16_t>::min() || value > std::numeric_limits<int16_t>::max())
					std::cout << "Overflow" << std::endl;
				break;
			}
			case Int32 :
			{
				value = std::stoi(this->toString()) % std::stoi(rhs.toString());
				if (value < std::numeric_limits<int32_t>::min() || value > std::numeric_limits<int32_t>::max())
					std::cout << "Overflow";
				break;
			}
			case Float :
				std::cout << "error" << std::endl;	break;
			case Double :
				std::cout << "error" << std::endl; 	break;
		}
		return (fac.createOperand(p, std::to_string(value)));
	}

private:
	std::string _value;
	eOperandType _type;
};

#endif
