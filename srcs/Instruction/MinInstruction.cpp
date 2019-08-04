//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#include "AInstruction.hpp"

MinInstruction::MinInstruction(Token *tok)
{
	instructionToken = tok;
}

void MinInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	const IOperand	*minOperand;

	if (stack.empty())
		throw EmptyStackException();

	minOperand = stack.front();

	for (auto dequeIterator = stack.begin();
	dequeIterator != stack.end(); ++dequeIterator)
	{
		if (stod(minOperand->toString()) > stod((*dequeIterator)->toString()))
			minOperand = *dequeIterator;
	}
	std::cout << "Min: " << minOperand->toString() << std::endl;
}