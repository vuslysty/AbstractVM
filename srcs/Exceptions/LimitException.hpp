//
// Created by Vladyslav USLYSTYI on 2019-07-31.
//

#ifndef ABSTRACTVM_LIMITEXCEPTION_HPP
#define ABSTRACTVM_LIMITEXCEPTION_HPP

//-------------------------Limits-----------------------------------------------

#include "ExceptionAVM.hpp"

class LimitException : public ExceptionAVM
{
public:

	LimitException();
};

class ValueOverflow : public LimitException
{
public:
	ValueOverflow();
	ValueOverflow(unsigned int row, unsigned int col);
	ValueOverflow(std::string const &val, unsigned int row, unsigned int col);
};

class ValueUnderflow : public LimitException
{
public:
	ValueUnderflow();
	ValueUnderflow(unsigned int row, unsigned int col);
	ValueUnderflow(std::string const &val, unsigned int row, unsigned int col);
};

#endif //ABSTRACTVM_LIMITEXCEPTION_HPP
