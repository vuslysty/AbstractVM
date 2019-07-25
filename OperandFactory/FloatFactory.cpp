//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "FloatFactory.hpp"

const inline IOperand* FloatFactory::createOperand(std::string value) const
{
	return new Operand<float >(value);
}

const IOperand* FloatFactory::createOperand(const void *value) const
{
	return new Operand<float >(const_cast<void *>(value));
}