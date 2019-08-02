//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#ifndef ABSTRACTVM_RUNTIMEEXCEPTIONS_HPP
#define ABSTRACTVM_RUNTIMEEXCEPTIONS_HPP


#include "ExceptionAVM.hpp"
#include "../Instruction/AInstruction.hpp"

class RunTimeExceptions : public ExceptionAVM
{
public:

	RunTimeExceptions() = default;
	RunTimeExceptions(std::string const &mes, AInstruction *inst);
};

class EmptyStackException : public RunTimeExceptions
{
public:

	EmptyStackException();
};

class PopOnEmptyStackException : public RunTimeExceptions
{
public:
	PopOnEmptyStackException();
};

class DivisionByZeroException : public RunTimeExceptions
{
public:
	DivisionByZeroException();
};

class ModuloByZeroException : public RunTimeExceptions
{
public:
	ModuloByZeroException();
};

class AssertIsNotTrueException : public RunTimeExceptions
{
public:
	AssertIsNotTrueException();
};

class LessThanTwoElemException : public RunTimeExceptions
{
public:
	LessThanTwoElemException();
};

class ValueIsNotASCIIException : public RunTimeExceptions
{
public:
	ValueIsNotASCIIException();
};

class InvalidBinaryOperationException : public RunTimeExceptions
{
public:
	InvalidBinaryOperationException();
};




#endif //ABSTRACTVM_RUNTIMEEXCEPTIONS_HPP
