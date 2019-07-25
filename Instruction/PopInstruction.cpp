//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "PopInstruction.hpp"
#include "../ExceptionAVM.hpp"

PopInstruction::PopInstruction(int line)
{
	this->line = line;
}

void PopInstruction::doInstruction(std::deque<const IOperand*> &stack)
{
	if (stack.empty())
		throw ExceptionAVM::PopOnEmptyStack();
	else
		stack.pop_front();
}