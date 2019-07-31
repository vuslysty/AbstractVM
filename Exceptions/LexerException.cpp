//
// Created by Vladyslav USLYSTYI on 2019-07-31.
//

#include <sstream>
#include "ExceptionAVM.hpp"

//-------------------------- Lexer Exception -----------------------------------

LexerException::LexerException()
{
	message = "Lexical error";
}

LexerException::LexerException(std::string const &message, std::string const &value, unsigned int row,
							   unsigned int col) : LexerException()
{
	std::stringstream	stream;

	stream << this->message << " at [" << row << ":" << col << "] : " << message;

	if (value.size() != 0)
		stream << "; bad value: \"" << value << "\"";

	this->message = stream.str();
}