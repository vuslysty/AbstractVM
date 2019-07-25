//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AssertInstruction.hpp"
#include "../ExceptionAVM.hpp"

DivInstruction::DivInstruction(int line)
{
	this->line = line;
}

void DivInstruction::doInstruction(std::deque<const IOperand*> &stack)
{
	if (stack.size() < 2)
		throw ExceptionAVM::LessThanTwoElem();
	else
	{
		const IOperand	*first = stack.front();
		stack.pop_front();

		const IOperand	*second = stack.front();
		stack.pop_front();

		const IOperand	*result = *second / *first;

		stack.push_front(result);
	}
}