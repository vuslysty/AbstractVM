//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#include "AInstruction.hpp"

BackInstruction::BackInstruction(Token *tok)
{
	instructionToken = tok;
}

void BackInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw EmptyStackException();

	std::cout << "Back element: " << stack.back()->toString() << std::endl;
}