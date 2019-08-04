//
// Created by Vladyslav USLYSTYI on 2019-07-31.
//

#include <sstream>
#include "LimitException.hpp"

LimitException::LimitException()
{
	message = "Limit error";
}

static std::string getPositionOfError(unsigned int row, unsigned int col)
{
	std::stringstream	stream;

	stream << "at [" << row << ":" << col << "]";
	return (stream.str());
}

//---------------Overflow--------------

ValueOverflow::ValueOverflow()
{
	message += ": value overflow";
}

ValueOverflow::ValueOverflow(unsigned int row, unsigned int col)
{
	message += " " + getPositionOfError(row, col);
}

ValueOverflow::ValueOverflow(std::string const &val, unsigned int row, unsigned int col) :
	ValueOverflow(row, col)
{
	message += ": value overflow \'" + val + "\'";
}


//---------------Overflow--------------

ValueUnderflow::ValueUnderflow()
{
	message += ": value underflow";
}

ValueUnderflow::ValueUnderflow(unsigned int row, unsigned int col)
{
	message += " " + getPositionOfError(row, col);
}

ValueUnderflow::ValueUnderflow(std::string const &val, unsigned int row, unsigned int col) :
		ValueUnderflow(row, col)
{
	message += ": value underflow \'" + val + "\'";
}