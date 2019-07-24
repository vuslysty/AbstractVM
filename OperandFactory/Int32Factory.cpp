//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Int32Factory.hpp"
#include "../Operand.hpp"

const IOperand* Int32Factory::createOperand(std::string value) const
{
	return new Operand<int32_t >(value);
}

const IOperand* Int32Factory::createOperand(void *value) const
{
	return new Operand<int32_t >(value);
}
