//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include <cfloat>
#include <sstream>
#include "IOperand.hpp"
#include "ExceptionAVM.hpp"
#include "Convertor.hpp"
#include <iomanip>

template <class T>
class 	Operand : public IOperand
{
	eOperandType			type;
	T						value;
	mutable std::string		strValue;

	Operand() : type(Int32), value(0) {};

public:

	explicit Operand(std::string const &value)
	{
		long double tmp;

		if (typeid(T) == typeid(int8_t))
			type = Int8;
		else if (typeid(T) == typeid(int16_t))
			type = Int16;
		else if (typeid(T) == typeid(int32_t))
			type = Int32;
		else if (typeid(T) == typeid(float))
			type = Float;
		else
			type = Double;
		try
		{
			tmp = std::stold(value);
		}
		catch (std::exception &e)
		{
			if (value[0] == '-')
				throw ExceptionAVM::ValueUnderflow();
			else
				throw ExceptionAVM::ValueOverflow();
		}
		checkOverAndUnderFlow(tmp, type);
		this->value = static_cast<T>(tmp);
	}

	Operand(Operand const &src) : type(src.type), value(src.value) {}

	Operand	&operator=(Operand const &rhs)
	{
		if (this != &rhs)
		{
			this->value = *reinterpret_cast<T*>(const_cast<void*>(rhs.getValue()));
			this->type = rhs.getType();
		}
		return (*this);
	}

	~Operand() final = default;

	int 				getPrecision() const final
	{
		return static_cast<int>(type);
	}

	eOperandType 		getType() const final
	{
		return type;
	}

	const std::string	&toString(bool mod = true) const final
	{
		strValue = getStrValueWithPrecision(static_cast<long double>(value), type, mod);

		return strValue;
	}

	bool                operator==(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType() &&
			this->value == static_cast<T>(stod(rhs.toString())))
			return true;
		else
			return false;
	}

	bool                operator!=(IOperand const &rhs) const final
	{
		return !(*this == rhs);
	}

	IOperand const		*operator+(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			T				value2 = static_cast<T>(stold(rhs.toString()));
			long double 	result = static_cast<long double>(this->value) + static_cast<long double>(value2);

			checkOverAndUnderFlow(result, type);

			return (OperandFactory::create(this->type, getStrValueWithPrecision(result, type, true)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() + conv.getRight());
		}
	}

	IOperand const		*operator-(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			T				value2 = static_cast<T>(stold(rhs.toString()));
			long double 	result = static_cast<long double>(this->value) - static_cast<long double>(value2);

			checkOverAndUnderFlow(result, type);

			return (OperandFactory::create(this->type, getStrValueWithPrecision(result, type, true)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() - conv.getRight());
		}
	}

	IOperand const		*operator*(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			T				value2 = static_cast<T>(stold(rhs.toString()));
			long double 	result = static_cast<long double>(this->value) * static_cast<long double>(value2);

			checkOverAndUnderFlow(result, type);

			return (OperandFactory::create(this->type, getStrValueWithPrecision(result, type, true)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() * conv.getRight());
		}
	}

	IOperand const		*operator/(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			T				value2 = static_cast<T>(stold(rhs.toString()));
			long double 	result = static_cast<long double>(this->value) / static_cast<long double>(value2);

			if (value2 == 0)
				throw ExceptionAVM::DivisionByZero();

			checkOverAndUnderFlow(result, type);

			return (OperandFactory::create(this->type, getStrValueWithPrecision(result, type, true)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() / conv.getRight());
		}
	}

	IOperand const		*operator%(IOperand const &rhs) const final
	{
		if (type == Float || type == Double || rhs.getType() == Float ||
			rhs.getType() == Double)
			throw ExceptionAVM::InvalidBinaryOperation();

		if (this->type == rhs.getType())
		{
			T value2 = static_cast<T>(stold(rhs.toString()));
			int result =
					static_cast<int>(this->value) % static_cast<int>(value2);

			if (value2 == 0)
				throw ExceptionAVM::DivisionByZero();

			return (OperandFactory::create(this->type, std::to_string(result)));
		}
		else
		{
			Convertor conv(*this, rhs);
			return (conv.getLeft() % conv.getRight());
		}
	}
};

#endif //ABSTRACTVM_OPERAND_HPP
