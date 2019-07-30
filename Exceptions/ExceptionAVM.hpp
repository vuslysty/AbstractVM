//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#ifndef ABSTRACTVM_EXCEPTIONAVM_HPP
#define ABSTRACTVM_EXCEPTIONAVM_HPP

#include <exception>
#include <string>
#include "../Lexer/Token.hpp"
#include <deque>

class ExceptionAVM : public std::exception
{
public:

	virtual const char 			*what() const _NOEXCEPT = 0;
};

class LexerException : public ExceptionAVM
{
	std::string	message;

public:

	LexerException();
	LexerException(std::string const &message, std::string const &value, unsigned int row, unsigned int col);

	LexerException(LexerException const &src) _NOEXCEPT;
	LexerException &operator=(LexerException const &rhs);
	~LexerException() _NOEXCEPT;


	const char 			*what() const _NOEXCEPT final;
};

class ParserException : public ExceptionAVM
{
	std::string	message;

public:

	ParserException();
	ParserException(bool isError, std::string const &message,
					std::deque<Token *>::iterator start, std::deque<Token *>::iterator end);

	ParserException(ParserException const &src) _NOEXCEPT;
	ParserException &operator=(ParserException const &rhs);
	~ParserException() _NOEXCEPT;


	const char 			*what() const _NOEXCEPT final;
};

#endif //ABSTRACTVM_EXCEPTIONAVM_HPP
