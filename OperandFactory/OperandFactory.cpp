//
// Created by Vladyslav USLYSTYI on 2019-07-26.
//

#include "OperandFactory.hpp"
#include "../Operand.hpp"

const IOperand* Int8Factory::createOperand(std::string value) const
{
	return new Operand<int8_t >(value);
}

const IOperand* Int16Factory::createOperand(std::string value) const
{
	return new Operand<int16_t >(value);
}

const IOperand* Int32Factory::createOperand(std::string value) const
{
	return new Operand<int32_t >(value);
}

const IOperand* FloatFactory::createOperand(std::string value) const
{
	return new Operand<float >(value);
}

const IOperand* DoubleFactory::createOperand(std::string value) const
{
	return new Operand<double >(value);
}