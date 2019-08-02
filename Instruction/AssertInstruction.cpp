//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../OperandFactory/OperandFactory.hpp"
#include "../ExceptionAVM.hpp"
#include "../Exceptions/RunTimeExceptions.hpp"


void AssertInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw EmptyStackException();
	if (*operand != *stack.front())
		throw AssertIsNotTrueException();
}

AssertInstruction::AssertInstruction(Token *tok, eOperandType type,
									 std::string const &value)
{
	instructionToken = tok;
	operand = OperandFactory::create(type, value);
}