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
protected:
	static std::string	message;

	ExceptionAVM() = default;
	ExceptionAVM(ExceptionAVM const &src)  = default;
	ExceptionAVM &operator=(ExceptionAVM const &rhs) = default;

public:
	const char 			*what() const _NOEXCEPT final; // just one what
	virtual ~ExceptionAVM() = default;
};

class LexerException : public ExceptionAVM
{
public:
	LexerException();
	LexerException(std::string const &message, std::string const &value,
			unsigned int row, unsigned int col);
};

class ParserException : public ExceptionAVM
{
public:
	ParserException();
	ParserException(bool isError, std::string const &message,
					std::deque<Token *>::iterator start,
					std::deque<Token *>::iterator end);
};

#endif //ABSTRACTVM_EXCEPTIONAVM_HPP