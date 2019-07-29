//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../ExceptionAVM.hpp"

void Lexer::errorMinus()
{
	workBeforeException();
	throw ExceptionAVM::UndeclaratedIdentifier(); //must change
}

void Lexer::errorDot()
{
	workBeforeException();
	throw ExceptionAVM::UndeclaratedIdentifier(); //must change
}

void Lexer::errorIdent()
{
	workBeforeException();
	throw ExceptionAVM::UndeclaratedIdentifier();
}

void Lexer::errorMultilineComment()
{
	workBeforeException();
	throw ExceptionAVM::UndeclaratedIdentifier(); //must change
}