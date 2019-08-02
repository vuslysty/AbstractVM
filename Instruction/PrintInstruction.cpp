//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include <iostream>
#include "AInstruction.hpp"
#include "../ExceptionAVM.hpp"

#include "../IOperand.hpp"
#include "../Exceptions/RunTimeExceptions.hpp"

PrintInstruction::PrintInstruction(Token *tok)
{
	instructionToken = tok;
}

void PrintInstruction::doInstruction(std::deque<const IOperand*> &stack) const
{
	if (stack.empty())
		throw EmptyStackException();
	if (stack.front()->getType() == Int8)
		std::cout << static_cast<char>(stoi(stack.front()->toString(true))) << std::endl;
	else
		throw ValueIsNotASCIIException();
}