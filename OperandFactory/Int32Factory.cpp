//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Int32Factory.hpp"

const inline IOperand* Int32Factory::createOperand(std::string value) const
{
	return new Operand<int32_t >(value);
}

const IOperand* Int32Factory::createOperand(const void *value) const
{
	return new Operand<int32_t >(const_cast<void *>(value));
}
