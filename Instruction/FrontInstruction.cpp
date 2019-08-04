//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#include "AInstruction.hpp"

FrontInstruction::FrontInstruction(Token *tok)
{
	instructionToken = tok;
}

void FrontInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw EmptyStackException();

	std::cout << "Front element: " << stack.front()->toString() << std::endl;
}