//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AssertInstruction.hpp"
#include "../ExceptionAVM.hpp"

void AssertInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw ExceptionAVM::EmptyStack();
	if (operand )
}