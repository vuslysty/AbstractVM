//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../ExceptionAVM.hpp"

void Lexer::errorMinus()
{
	throw ExceptionAVM::UndeclaratedIdentifier(); //must change
}

void Lexer::errorDot()
{
	throw ExceptionAVM::UndeclaratedIdentifier(); //must change
}

void Lexer::errorIdent()
{
	throw ExceptionAVM::UndeclaratedIdentifier();
}

void Lexer::errorMultilineComment()
{
	throw ExceptionAVM::UndeclaratedIdentifier(); //must change
}