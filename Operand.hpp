//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include <cfloat>
#include <sstream>
#include "Fsm additions/Fsm.hpp"
#include "IOperand.hpp"
#include "ExceptionAVM.hpp"
#include "OperandFactory/OperandCreator.hpp"
#include "Convertor.hpp"
#include <iomanip>

template <class T>
class 	Operand : public IOperand
{
	eOperandType	type;
	T				value;

	Operand() : type(Int32), value(0) {};

public:

	T getValue()
	{
		return value;
	}

	explicit Operand(std::string const &value);

	explicit Operand(int8_t value) : type(Int8), value(value) {}
	explicit Operand(int16_t value) : type(Int16), value(value) {}
	explicit Operand(int32_t value) : type(Int32), value(value) {}
	explicit Operand(float value) : type(Float), value(value) {}
	explicit Operand(double value) : type(Double), value(value) {}


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

//	const void				*getValue() const final
//	{
//		return (&value);
//	}

	const std::string	&toString(int n = 20) const final
	{
		static bool			wasWriting = false;
		static std::string	str;

		if (!wasWriting)
		{
			std::ostringstream out;
			out << std::fixed << std::showpoint << std::setprecision(n) << value;
			str = out.str();
			wasWriting = true;
		}

		return str;
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
			OperandCreator	*creator = OperandCreator::getInstance();
			T				value2 = static_cast<T>(stold(rhs.toString()));
			T 				result = this->value + value2;

			if (result - value2 != this->value)
			{
				if (this->value < 0 && value2 < 0)
					throw ExceptionAVM::ValueUnderflow();
				else
					throw ExceptionAVM::ValueOverflow();
			}

			return (creator->createOperand(this->type, std::to_string(result)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() + conv.getRight());
		}
	}

	IOperand const		*operator-(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T				value2 = static_cast<T>(stold(rhs.toString()));
			T 				result = this->value - value2;

			if (result + value2 != this->value)
			{
				if (this->value < 0 && value2 > 0)
					throw ExceptionAVM::ValueUnderflow();
				else
					throw ExceptionAVM::ValueOverflow();
			}

			return (creator->createOperand(this->type, std::to_string(result)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() - conv.getRight());
		}
	}

	IOperand const		*operator*(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T				value2 = static_cast<T>(stold(rhs.toString()));
			T 				result = this->value * value2;

			if (result / value2 != this->value)
			{
				if ((this->value < 0 && value2 < 0) || (this->value > 0 && (value2 > 0 && value2 <= 1)))
					throw ExceptionAVM::ValueOverflow();
				else
					throw ExceptionAVM::ValueUnderflow();
			}

			return (creator->createOperand(this->type, std::to_string(result)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() * conv.getRight());
		}
	}

	IOperand const		*operator/(IOperand const &rhs) const final
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T				value2 = static_cast<T>(stold(rhs.toString()));
			if (value2 == 0)
				throw ExceptionAVM::DivisionByZero();

			T 				result = this->value / value2;

			if (result * value2 != this->value)
			{
				if ((this->value > 0 && (value2 > 0 && value2 <= 1)))
					throw ExceptionAVM::ValueOverflow();
				else
					throw ExceptionAVM::ValueUnderflow();
			}

			return (creator->createOperand(this->type, std::to_string(result)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() / conv.getRight());
		}
	}

	IOperand const		*operator%(IOperand const &rhs) const final
	{
		if (type == Float || type == Double || rhs.getType() == Float || rhs.getType() == Double)
			throw ExceptionAVM::InvalidBinaryOperation();


		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T	value2 = static_cast<T>(stold(rhs.toString()));
			if (value2 == 0)
				throw ExceptionAVM::ModuloByZero();

			int32_t tmp = static_cast<int32_t >(this->value) % static_cast<int32_t >(value2);
			T 		result = static_cast<T>(tmp);

			return (creator->createOperand(this->type, std::to_string(result)));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() % conv.getRight());
		}
	}
};

#endif //ABSTRACTVM_OPERAND_HPP
