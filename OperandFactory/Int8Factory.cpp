//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Int8Factory.hpp"
#include "../Operand.hpp"

const IOperand* Int8Factory::createOperand(std::string value) const
{
	return new Operand<int8_t >(value);
}

const IOperand* Int8Factory::createOperand(const void *value) const
{
	return new Operand<int8_t >(const_cast<void *>(value));
}