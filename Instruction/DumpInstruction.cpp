//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "DumpInstruction.hpp"
#include "../ExceptionAVM.hpp"

DumpInstruction::DumpInstruction(int line)
{
	this->line = line;
}

void DumpInstruction::doInstruction(std::deque<const IOperand*> &stack)
{
	for (auto item : stack)
		std::cout << item->toString() << std::endl;
}