//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#ifndef ABSTRACTVM_EXCEPTIONAVM_HPP
#define ABSTRACTVM_EXCEPTIONAVM_HPP

#include <exception>
#include <string>

class ExceptionAVM : public std::exception
{
public:

	virtual const char 			*what(void) const _NOEXCEPT = 0;
};

class LexerException : public ExceptionAVM
{
	std::string	message;


public:

	LexerException(std::string message, std::string value, unsigned int row, unsigned int col);


	const char 			*what(void) const throw();
};

#endif //ABSTRACTVM_EXCEPTIONAVM_HPP
