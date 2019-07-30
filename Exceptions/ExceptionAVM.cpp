//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#include <sstream>
#include "ExceptionAVM.hpp"

LexerException::LexerException() :
 message("Lexical error")
{}

LexerException::LexerException(std::string const &message, std::string const &value, unsigned int row,
							   unsigned int col) : LexerException()
{
	std::stringstream	stream;

	stream << this->message << " at [" << row << ":" << col << "] : " << message;

	if (value.size() != 0)
		stream << "; bad value: \"" << value << "\"";

	this->message = stream.str();
}

LexerException::LexerException(LexerException const &) _NOEXCEPT {}

LexerException& LexerException::operator=(LexerException const &) {return *this;}

LexerException::~LexerException() _NOEXCEPT {}

const char* LexerException::what() const _NOEXCEPT
{
	return message.c_str();
}



std::string	getExpression(std::deque<Token *>::iterator start, std::deque<Token *>::iterator end)
{
	std::stringstream	stream;
	bool				spaceTrigger = false;

	while (start != end)
	{
		if (!spaceTrigger)
			spaceTrigger = true;
		else
			stream << " ";

		stream << (*start)->getValue();
		start++;
	}
	return (stream.str());
}

std::string	getPosition(std::deque<Token *>::iterator end)
{
	std::stringstream	stream;

	end--;
	stream << "[" << (*end)->getRow() << ":" << (*end)->getCol() << "]";
	return (stream.str());
}


ParserException::ParserException() :
		message("Syntax")
{}

ParserException::ParserException(bool isError, std::string const &message,
		std::deque<Token *>::iterator start, std::deque<Token *>::iterator end) : ParserException()
{
	std::stringstream	stream;

	stream << this->message << " ";
	if (isError)
		stream << "error";
	else
		stream << "warning";

	stream << " at " << getPosition(end) << " : " << message << "; ";
	stream << "bad expression \"" << getExpression(start, end) << "\"";

	this->message = stream.str();
}

ParserException::ParserException(ParserException const &) _NOEXCEPT {}

ParserException& ParserException::operator=(ParserException const &) {return *this;}

ParserException::~ParserException() _NOEXCEPT {}

const char* ParserException::what() const _NOEXCEPT
{
	return message.c_str();
}