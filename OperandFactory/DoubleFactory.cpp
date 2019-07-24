//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "DoubleFactory.hpp"
#include "../Operand.hpp"

const IOperand* DoubleFactory::createOperand(std::string value) const
{
	return new Operand<double >(value);
}

const IOperand* DoubleFactory::createOperand(void *value) const
{
	return new Operand<double >(value);
}