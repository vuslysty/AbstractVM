//
// Created by Vladyslav USLYSTYI on 2019-08-01.
//

#include "Operand.hpp"

template <>
void	Operand<int8_t >::setType()
{
	type = Int8;
}

template <>
void	Operand<int16_t >::setType()
{
	type = Int16;
}

template <>
void	Operand<int32_t >::setType()
{
	type = Int32;
}

template <>
void	Operand<float >::setType()
{
	type = Float;
}

template <>
void	Operand<double >::setType()
{
	type = Double;
}