//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "DumpInstruction.hpp"
#include "../ExceptionAVM.hpp"
#include <iostream>

#include "../IOperand.hpp"

void DumpInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	for (auto item : stack)
		std::cout << item->toString(2) << std::endl;
}