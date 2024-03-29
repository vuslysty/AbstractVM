//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../Exceptions/RunTimeExceptions.hpp"

PopInstruction::PopInstruction(Token *tok)
{
	instructionToken = tok;
}

void PopInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	const IOperand	*tmp;

	if (stack.empty())
		throw PopOnEmptyStackException();
	else
	{
		tmp = stack.front();
		stack.pop_front();
		delete tmp;
	}
}