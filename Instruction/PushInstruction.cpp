//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "PushInstruction.hpp"
#include "../OperandFactory/OperandCreator.hpp"

void PushInstruction::doInstruction(std::deque<const IOperand *> &stack) const
{
	stack.push_front(operand);
}

PushInstruction::PushInstruction(eOperandType type,
									 std::string const &value)
{
	OperandCreator	*creator = OperandCreator::getInstance();

	operand = creator->createOperand(type, value);
}