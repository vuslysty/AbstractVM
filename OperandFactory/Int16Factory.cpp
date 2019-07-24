//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Int16Factory.hpp"

#include "../Operand.hpp"

const IOperand* Int16Factory::createOperand(std::string value) const
{
	return new Operand<int16_t >(value);
}

const IOperand* Int16Factory::createOperand(void *value) const
{
	return new Operand<int16_t >(value);
}