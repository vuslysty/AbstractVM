//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../Exceptions/ExceptionAVM.hpp"

void Lexer::errorMinus()
{
	std::string	value;

	workBeforeException(0);

	value.assign(str, startTokenTMP, carret - startTokenTMP + (str[carret] == 0 || str[carret] == '\n' ? 0 : 1));
	throw LexerException("Expected not digit after minus", value, row, col);
}

void Lexer::errorDot()
{
	std::string	value;

	workBeforeException(0);

	value.assign(str, startTokenTMP, carret - startTokenTMP + (str[carret] == 0 || str[carret] == '\n' ? 0 : 1));
	throw LexerException("Expected not digit after floating point dot", value, row, col);
}

void Lexer::errorIdent()
{
	std::string	value;

	workBeforeException(1);

	value.assign(str, startTokenTMP, 1);
	throw LexerException("Expected undeclared identifier", value, row, startColumnTMP);
}

void Lexer::errorMultilineComment()
{
	std::string	value;

	if (state == 8)
	{
		moveCarretBack();
		errorIdent();
	}

	workBeforeException(0);

	value.assign(str, startTokenTMP, carret - startTokenTMP);
	throw LexerException("Multiline comment was not closed", "", startRow, startColumnTMP);
}