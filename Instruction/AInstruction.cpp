//
// Created by Vladyslav USLYSTYI on 2019-07-27.
//

#include "AInstruction.hpp"
#include "../ExceptionAVM.hpp"

std::pair<const IOperand *, const IOperand *> AInstruction::getTwoElemFromStack(
		std::deque<const IOperand *> &stack) const
{
	if (stack.size() < 2)
		throw ExceptionAVM::LessThanTwoElem();

	std::pair<const IOperand *, const IOperand *>	pair;

	pair.first = stack.front();
	stack.pop_front();
	pair.second = stack.front();
	stack.pop_front();

	return pair;
}

unsigned int AInstruction::getRow() const
{
	return instructionToken->getRow();
}

unsigned int AInstruction::getColumn() const
{
	return instructionToken->getCol();
}