//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#include "AInstruction.hpp"

MaxInstruction::MaxInstruction(Token *tok)
{
	instructionToken = tok;
}

void MaxInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	const IOperand	*maxOperand;

	if (stack.empty())
		throw EmptyStackException();

	maxOperand = stack.front();

	for (auto dequeIterator = stack.begin();
	dequeIterator != stack.end(); ++dequeIterator)
	{
		if (stod(maxOperand->toString()) < stod((*dequeIterator)->toString()))
			maxOperand = *dequeIterator;
	}
	std::cout << "Max: " << maxOperand->toString() << std::endl;
}