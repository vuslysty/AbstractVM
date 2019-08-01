//
// Created by Vladyslav USLYSTYI on 2019-07-31.
//

#include <sstream>
#include "ExceptionAVM.hpp"

//------------------------- Parser Exception -----------------------------------


static std::string	getExpression(std::deque<Token *>::iterator start, std::deque<Token *>::iterator end)
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

static std::string	getPosition(std::deque<Token *>::iterator end)
{
	std::stringstream	stream;

	end--;
	stream << "[" << (*end)->getRow() << ":" << (*end)->getCol() << "]";
	return (stream.str());
}

ParserException::ParserException()
{
	message = "Syntax";
}

ParserException::ParserException(bool isError, std::string const &m,
								 std::deque<Token *>::iterator start, std::deque<Token *>::iterator end) : ParserException()
{
	std::stringstream	stream;

	stream << message << " ";
	if (isError)
		stream << "error";
	else
		stream << "warning";

	stream << " at " << getPosition(end) << " : " << m << "; ";
	stream << "The expression we got \"" << getExpression(start, end) << "\"";

	message = stream.str();
}
