//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "AInstruction.hpp"
#include "../OperandFactory/OperandFactory.hpp"
#include "../ExceptionAVM.hpp"


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
	operand = OperandFactory::create(type, value);
}