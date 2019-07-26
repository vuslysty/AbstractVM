//
// Created by Vladyslav USLYSTYI on 2019-07-26.
//

#include "Operand.hpp"

template<>
const		IOperand *Operand<float >::operator%(IOperand const &) const
{
	throw ExceptionAVM::InvalidBinaryOperation();
}

template<>
const		IOperand *Operand<double >::operator%(IOperand const &) const
{
	throw ExceptionAVM::InvalidBinaryOperation();
}


template <>
Operand<int8_t>::Operand(std::string const &value)
{
	int tmp;

	try{
		tmp = std::stoi(value);
	} catch (std::exception &e){
		if (value[0] == '-')
			throw ExceptionAVM::ValueUnderflow();
		else
			throw ExceptionAVM::ValueOverflow();
	}

	if (tmp > INT8_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT8_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int8_t>(tmp);
	type = Int8;
}

//template <>
//Operand<int8_t >::Operand(void *value) : type(Int8)
//{
//	long tmp = *reinterpret_cast<int64_t*>(value);
//
//	if (tmp > INT8_MAX)
//		throw ExceptionAVM::ValueOverflow();
//	else if (tmp < INT8_MIN)
//		throw ExceptionAVM::ValueUnderflow();
//
//	this->value = static_cast<int8_t>(tmp);
//}

template <>
Operand<int16_t>::Operand(std::string const &value)
{
	int tmp;

	try{
		tmp = std::stoi(value);
	} catch (std::exception &e){
		if (value[0] == '-')
			throw ExceptionAVM::ValueUnderflow();
		else
			throw ExceptionAVM::ValueOverflow();
	}

	if (tmp > INT16_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < INT16_MIN)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<int16_t>(tmp);
	type = Int16;
}

//template <>
//Operand<int16_t >::Operand(void *value) : type(Int16)
//{
//	long tmp = *reinterpret_cast<int64_t*>(value);
//
//	if (tmp > INT16_MAX)
//		throw ExceptionAVM::ValueOverflow();
//	else if (tmp < INT16_MIN)
//		throw ExceptionAVM::ValueUnderflow();
//
//	this->value = static_cast<int16_t>(tmp);
//}

template <>
Operand<int32_t>::Operand(std::string const &value)
{
	int tmp;

	try{
		tmp = std::stoi(value);
	} catch (std::exception &e){
		if (value[0] == '-')
			throw ExceptionAVM::ValueUnderflow();
		else
			throw ExceptionAVM::ValueOverflow();
	}
	this->value = tmp;
	type = Int32;
}

//template <>
//Operand<int32_t >::Operand(void *value) : type(Int32)
//{
//	long tmp = *reinterpret_cast<int32_t*>(value);
//
//	if (tmp > INT32_MAX)
//		throw ExceptionAVM::ValueOverflow();
//	else if (tmp < INT32_MIN)
//		throw ExceptionAVM::ValueUnderflow();
//
//	this->value = static_cast<int32_t>(tmp);
//}

template <>
Operand<float>::Operand(std::string const &value)
{
	double tmp;

	try{
		tmp = std::stod(value);
	} catch (std::exception &e){
		if (value[0] == '-')
			throw ExceptionAVM::ValueUnderflow();
		else
			throw ExceptionAVM::ValueOverflow();
	}

	if (tmp > FLT_MAX)
		throw ExceptionAVM::ValueOverflow();
	else if (tmp < -FLT_MAX)
		throw ExceptionAVM::ValueUnderflow();

	this->value = static_cast<float >(tmp);
	type = Float;
}

//template <>
//Operand<float >::Operand(void *value) : type(Float)
//{
//	long double tmp = *reinterpret_cast<long double*>(value);
//
//	if (tmp > FLT_MAX)
//		throw ExceptionAVM::ValueOverflow();
//	else if (tmp < -FLT_MAX)
//		throw ExceptionAVM::ValueUnderflow();
//
//	this->value = static_cast<float>(tmp);
//}


template <>
Operand<double >::Operand(std::string const &value)
{
	double tmp;

	try{
		tmp = std::stod(value);
	} catch (std::exception &e){
		if (value[0] == '-')
			throw ExceptionAVM::ValueUnderflow();
		else
			throw ExceptionAVM::ValueOverflow();
	}

	this->value = tmp;
	type = Double;
}

//template <>
//Operand<double >::Operand(void *value) : type(Double)
//{
//	long double tmp = *reinterpret_cast<long double*>(value);
//
//	if (tmp > DBL_MAX)
//		throw ExceptionAVM::ValueOverflow();
//	else if (tmp < -DBL_MAX)
//		throw ExceptionAVM::ValueUnderflow();
//
//	this->value = static_cast<double >(tmp);
//}