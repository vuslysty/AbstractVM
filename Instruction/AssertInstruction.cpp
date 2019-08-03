//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../OperandFactory/OperandFactory.hpp"
#include "../Exceptions/RunTimeExceptions.hpp"

AssertInstruction::AssertInstruction() : operand(nullptr) {}
AssertInstruction::AssertInstruction(AssertInstruction const &) {}
AssertInstruction& AssertInstruction::operator=(AssertInstruction const &) {return *this;}
AssertInstruction::~AssertInstruction()
{
	if (!wasAddedToStack)
		delete operand;
}

AssertInstruction::AssertInstruction(Token *tok, eOperandType type,
									 std::string const &value)
{
	instructionToken = tok;
	wasAddedToStack = false;
	operand = OperandFactory::create(type, value);
}

void AssertInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw EmptyStackException();
	if (*operand != *stack.front())
		throw AssertIsNotTrueException();
	wasAddedToStack = true;
}
