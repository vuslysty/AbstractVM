//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../ExceptionAVM.hpp"
#include "../Exceptions/RunTimeExceptions.hpp"

PopInstruction::PopInstruction(Token *tok)
{
	instructionToken = tok;
}

void PopInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw PopOnEmptyStackException();
	else
		stack.pop_front();
}