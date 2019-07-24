//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AddInstruction.hpp"
#include "../ExceptionAVM.hpp"

AddInstruction::AddInstruction(int line)
{
	this->line = line;
}

void AddInstruction::doInstruction(std::deque<IOperand*> &stack)
{
	if (stack.size() < 2)
		throw ExceptionAVM::LessThanTwoElem();
	else
	{
		IOperand	*first = stack.front();
		stack.pop_front();

		IOperand	*second = stack.front();
		stack.pop_front();

		stack.push_front(*second + *first);

		first = static_cast<IOperand*>(stack.pop_front());
	}
}