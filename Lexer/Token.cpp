#include <utility>

//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Token.hpp"

Token::Token(eToken t, std::string value, unsigned long row, unsigned long col) :
	token(t), sValue(std::move(value)), row(row), col(col)
{}

Token::Token(Token const &src)
{
	*this = src;
}

Token& Token::operator=(Token const &rhs)
{
	if (this != &rhs)
	{
		this->token = rhs.token;
		this->sValue = rhs.sValue;
	}
	return (*this);
}

eToken Token::getToken() const
{
	return token;
}

std::string Token::getValue() const
{
	return sValue;
}

std::string Token::getTokenByStr() const
{
	return (sToken[token]);
}

unsigned long Token::getRow() const
{
	return row;
}

unsigned long Token::getCol() const
{
	return col;
}