//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"

bool Lexer::whiteCondition(const char c) const
{
	return (c == '\t' || c == ' ');
}

bool Lexer::alphaCondition(const char c) const
{
	return (isalpha(c));
}

bool Lexer::numCondition(const char c) const
{
	return (isdigit(c));
}

bool Lexer::openScopeCondition(const char c) const
{
	return (c == '(');
}

bool Lexer::closeScopeCondition(const char c) const
{
	return (c == ')');
}

bool Lexer::minusCondition(const char c) const
{
	return (c == '-');
}

bool Lexer::dotCondition(const char c) const
{
	return (c == '.');
}

bool Lexer::endLineCondition(const char c) const
{
	return (c == '\n');
}

bool Lexer::commentCondition(const char c) const
{
	return (c == ';');
}

bool Lexer::zeroCondition(const char c) const
{
	return (c == '\0');
}

bool Lexer::slashCondition(const char c) const
{
	return (c == '/');
}