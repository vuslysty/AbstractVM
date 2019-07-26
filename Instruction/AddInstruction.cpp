//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AddInstruction.hpp"
#include "../ExceptionAVM.hpp"
#include "../IOperand.hpp"

void AddInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.size() < 2)
		throw ExceptionAVM::LessThanTwoElem();
	else
	{
		const IOperand	*first = stack.front();
		stack.pop_front();

		const IOperand	*second = stack.front();
		stack.pop_front();

		const IOperand	*result = *second + *first;

		stack.push_front(result);
	}
}