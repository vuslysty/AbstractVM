//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "FloatFactory.hpp"
#include "../Operand.hpp"

const IOperand* FloatFactory::createOperand(std::string value) const
{
	return new Operand<float >(value);
}

const IOperand* FloatFactory::createOperand(void *value) const
{
	return new Operand<float >(value);
}