//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../IOperand.hpp"

ModInstruction::ModInstruction(Token *tok)
{
	instructionToken = tok;
}

void ModInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	std::pair<const IOperand *, const IOperand *>	pair;

	pair = getTwoElemFromStack(stack);
	try
	{
		stack.push_front(*pair.second % *pair.first);
		delete pair.first;
		delete pair.second;
	}
	catch (ExceptionAVM &e)
	{
		delete pair.first;
		delete pair.second;
		throw e;
	}
}