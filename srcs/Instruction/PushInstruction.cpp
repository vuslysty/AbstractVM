//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../OperandFactory/OperandFactory.hpp"

PushInstruction::PushInstruction() : operand(nullptr) {}
PushInstruction::PushInstruction(PushInstruction const &) {}
PushInstruction& PushInstruction::operator=(PushInstruction const &) {return *this;}
PushInstruction::~PushInstruction()
{
	if (!wasAddedToStack)
		delete operand;
}


PushInstruction::PushInstruction(Token *tok, eOperandType type,
								 std::string const &value)
{
	instructionToken = tok;
	wasAddedToStack = false;
	operand = OperandFactory::create(type, value);
}

void PushInstruction::doInstruction(std::deque<const IOperand *> &stack) const
{
	wasAddedToStack = true;
	stack.push_front(operand);
}
