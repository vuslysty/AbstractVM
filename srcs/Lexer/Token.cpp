#include <utility>

//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Token.hpp"

Token::Token(eToken t, std::string value, unsigned int row, unsigned int col) :
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

unsigned int Token::getRow() const
{
	return row;
}

unsigned int Token::getCol() const
{
	return col;
}