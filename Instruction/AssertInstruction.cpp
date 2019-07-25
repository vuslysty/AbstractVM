//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AssertInstruction.hpp"
#include "../ExceptionAVM.hpp"
#include "../OperandFactory/OperandCreator.hpp"

void AssertInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw ExceptionAVM::EmptyStack();
	if (*operand != *stack.front())
		throw ExceptionAVM::AssertIsNotTrue();
}

AssertInstruction::AssertInstruction(eOperandType type,
									 std::string const &value)
{
	OperandCreator	*creator = OperandCreator::getInstance();

	operand = creator->createOperand(type, value);
}