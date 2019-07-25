//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

#include <cfloat>
#include "Fsm additions/Fsm.hpp"
#include "IOperand.hpp"
#include "ExceptionAVM.hpp"
#include "OperandFactory/OperandCreator.hpp"
#include "Convertor.hpp"

template <class T>
class 	Operand : public IOperand
{
	eOperandType	type;
	T				value;

	Operand<T>() : type(Int32), value(0) {};

public:

	explicit Operand<T>(std::string const &value);

	explicit Operand<T>(void *value);

	explicit Operand<T>(Operand const &src)
	{
		*this = src;
	}

	Operand<T>	&operator=(Operand const &rhs)
	{
		if (this != &rhs)
		{
			this->value = rhs.getValue();
			this->type = rhs;
		}
	}

	~Operand<T>() {};

	int 				getPrecision() const
	{
		return static_cast<int>(type);
	}

	eOperandType 		getType() const
	{
		return type;
	}

	const void				*getValue() const
	{
		return (&value);
	}

	const std::string	&toString() const
	{
		static bool			wasWriting = false;
		static std::string	str;

		if (!wasWriting)
		{
			wasWriting = true;
			str = std::to_string(value);
		}

		return str;
	}

	IOperand const		*operator+(IOperand const &rhs) const
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T 				result = this->value + *reinterpret_cast<const T*>(rhs.getValue());
			return (creator->createOperand(this->type, &result));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() + conv.getRight());
		}
	}

	IOperand const		*operator-(IOperand const &rhs) const
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T 				result = this->value - *reinterpret_cast<const T*>(rhs.getValue());
			return (creator->createOperand(this->type, &result));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() - conv.getRight());
		}
	}

	IOperand const		*operator*(IOperand const &rhs) const
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T 				result = this->value * *reinterpret_cast<const T*>(rhs.getValue());
			return (creator->createOperand(this->type, &result));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() * conv.getRight());
		}
	}

	IOperand const		*operator/(IOperand const &rhs) const
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T 				result = this->value / *reinterpret_cast<const T*>(rhs.getValue());
			return (creator->createOperand(this->type, &result));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() / conv.getRight());
		}
	}

	IOperand const		*operator%(IOperand const &rhs) const
	{
		if (this->type == rhs.getType()) {
			OperandCreator	*creator = OperandCreator::getInstance();
			T 				result = this->value % *reinterpret_cast<const T*>(rhs.getValue());
			return (creator->createOperand(this->type, &result));
		}
		else {
			Convertor conv(*this, rhs);
			return (conv.getLeft() % conv.getRight());
		}
	}
};

template<>
const		IOperand *Operand<float >::operator%(IOperand const &rhs) const
{
		return *this / rhs;
}

template<>
const		IOperand *Operand<double >::operator%(IOperand const &rhs) const
{
	return *this / rhs;
}


template <>
Operand<int8_t>::Operand(std::string const &value)
{
	long tmp = std::stol(value);
	if (tmp > INT8_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT8_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int8_t>(tmp);
	type = Int8;
}

template <>
Operand<int8_t >::Operand(void *value) : type(Int8)
{
	long tmp = *reinterpret_cast<int64_t*>(value);

	if (tmp > INT8_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT8_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int8_t>(tmp);
}

template <>
Operand<int16_t>::Operand(std::string const &value)
{
	long tmp = std::stol(value);
	if (tmp > INT16_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT16_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int16_t>(tmp);
	type = Int16;
}

template <>
Operand<int16_t >::Operand(void *value) : type(Int16)
{
	long tmp = *reinterpret_cast<int64_t*>(value);

	if (tmp > INT16_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT16_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int16_t>(tmp);
}

template <>
Operand<int32_t>::Operand(std::string const &value)
{
	long tmp = std::stol(value);
	if (tmp > INT32_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT32_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int32_t >(tmp);
	type = Int32;
}

template <>
Operand<int32_t >::Operand(void *value) : type(Int32)
{
	long tmp = *reinterpret_cast<int64_t*>(value);

	if (tmp > INT32_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT32_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int32_t>(tmp);
}

template <>
Operand<float>::Operand(std::string const &value)
{
	long double tmp = std::stold(value);
	if (tmp > FLT_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < -FLT_MAX)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<float >(tmp);
	type = Float;
}

template <>
Operand<float >::Operand(void *value) : type(Float)
{
	long double tmp = *reinterpret_cast<long double*>(value);

	if (tmp > FLT_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < -FLT_MAX)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<float>(tmp);
}


template <>
Operand<double >::Operand(std::string const &value)
{
	long double tmp = std::stold(value);
	if (tmp > DBL_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < -DBL_MAX)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<double >(tmp);
	type = Double;
}

template <>
Operand<double >::Operand(void *value) : type(Double)
{
	long double tmp = *reinterpret_cast<long double*>(value);

	if (tmp > DBL_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < -DBL_MAX)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<double >(tmp);
}

#endif //ABSTRACTVM_OPERAND_HPP
