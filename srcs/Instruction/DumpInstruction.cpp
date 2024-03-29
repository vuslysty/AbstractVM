//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include <iostream>

#include "../IOperand.hpp"

DumpInstruction::DumpInstruction(Token *tok)
{
	instructionToken = tok;
}

void DumpInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	for (auto item : stack)
		std::cout << item->toString() << std::endl;
}