//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "PushInstruction.hpp"
#include "../OperandFactory/OperandCreator.hpp"

PushInstruction::PushInstruction() : operand(nullptr) {}
PushInstruction::PushInstruction(PushInstruction const &) {}
PushInstruction& PushInstruction::operator=(PushInstruction const &) {return *this;}
PushInstruction::~PushInstruction() = default;


PushInstruction::PushInstruction(eOperandType type,
								 std::string const &value)
{
	OperandCreator	*creator = OperandCreator::getInstance();

	operand = creator->createOperand(type, value);
}

void PushInstruction::doInstruction(std::deque<const IOperand *> &stack) const
{
	stack.push_front(operand);
}
