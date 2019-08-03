//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#include <sstream>
#include "RunTimeExceptions.hpp"
#include "../Instruction/AInstruction.hpp"

RunTimeExceptions::RunTimeExceptions(std::string const &mes, AInstruction *inst)
{
	std::stringstream	stream;

	stream << "Runtime error at [" << inst->getRow() << ":" << inst->getColumn() << "]";
	stream << " : " << mes;

	message.assign(stream.str());
}

EmptyStackException::EmptyStackException()
{
	message = "The stack is empty";
}

PopOnEmptyStackException::PopOnEmptyStackException()
{
	message = "Pop on empty stack";
}

DivisionByZeroException::DivisionByZeroException()
{
	message = "Division by zero";
}

ModuloByZeroException::ModuloByZeroException()
{
	message = "Modulo by zero";
}

AssertIsNotTrueException::AssertIsNotTrueException()
{
	message = "Assert operation is not true";
}

LessThanTwoElemException::LessThanTwoElemException()
{
	message = "Stack contains less than two elements";
}

ValueIsNotASCIIException::ValueIsNotASCIIException()
{
	message = "Value is not ASCII symbol";
}

InvalidBinaryOperationException::InvalidBinaryOperationException()
{
	message = "Invalid binary operation";
}