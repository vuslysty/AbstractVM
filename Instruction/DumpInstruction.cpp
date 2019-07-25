//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "DumpInstruction.hpp"
#include "../ExceptionAVM.hpp"

void DumpInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	for (auto item : stack)
		std::cout << item->toString() << std::endl;
}