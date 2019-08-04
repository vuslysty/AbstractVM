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

LexerException::LexerException(std::string const &m, std::string const &value, unsigned int row,
							   unsigned int col) : LexerException()
{
	std::stringstream	stream;

	stream << message << " at [" << row << ":" << col << "] : " << m;

	if (value.size() != 0)
		stream << "; The value we got: \"" << value << "\"";

	message = stream.str();
}