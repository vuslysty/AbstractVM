//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../ExceptionAVM.hpp"

void PopInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw ExceptionAVM::PopOnEmptyStack();
	else
		stack.pop_front();
}