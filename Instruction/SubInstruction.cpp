//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../ExceptionAVM.hpp"
#include "../IOperand.hpp"

void SubInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	std::pair<const IOperand *, const IOperand *>	pair;

	pair = getTwoElemFromStack(stack);
	stack.push_front(*pair.second - *pair.first);
}