//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../ExceptionAVM.hpp"

void Lexer::errorMinus()
{
	throw ExceptionAVM::InvalidInstruction();
}

void Lexer::errorDot()
{
	throw ExceptionAVM::InvalidInstruction(); //must change
}

void Lexer::errorIdent()
{
	throw ExceptionAVM::InvalidInstruction(); //must change
}