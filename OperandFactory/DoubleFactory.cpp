//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "DoubleFactory.hpp"

const inline IOperand* DoubleFactory::createOperand(std::string value) const
{
	return new Operand<double >(value);
}

const IOperand* DoubleFactory::createOperand(const void *value) const
{
	return new Operand<double >(const_cast<void *>(value));
}