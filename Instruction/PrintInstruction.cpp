//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include <iostream>
#include "PrintInstruction.hpp"
#include "../ExceptionAVM.hpp"

PrintInstruction::PrintInstruction(int line)
{
	this->line = line;
}

void PrintInstruction::doInstruction(std::deque<const IOperand*> &stack)
{
	if (stack.empty())
		throw ExceptionAVM::EmptyStack();
	if (stack.front()->getType() == Int8)
		std::cout << *reinterpret_cast<char*>(const_cast<void*>(stack.front()->getValue()));
	else
		throw ExceptionAVM::ValueIsNotASCII();
}