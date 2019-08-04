//
// Created by Vladyslav USLYSTYI on 2019-07-31.
//

#include <sstream>
#include "ExceptionAVM.hpp"

const char* ExceptionAVM::what() const _NOEXCEPT
{
	return message.c_str();
}

std::string ExceptionAVM::message = "";

InvalidFlagException::InvalidFlagException(char c)
{
	std::stringstream	stream;

	stream << RED_COLOR << "Error: " << STD_COLOR <<
	"Invalid execution flag '" << c << "'";

	message = stream.str();
}