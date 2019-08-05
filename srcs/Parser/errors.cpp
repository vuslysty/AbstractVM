//
// Created by Vladyslav USLYSTYI on 2019-07-30.
//

#include <sstream>
#include "Parser.hpp"
#include "../Exceptions/ExceptionAVM.hpp"

void Parser::errorNotValue()
{
	std::stringstream				stream;
	auto							tmp = iter;

	stream << "After instruction \'" << sInstrutions[getInstructionType()] << "\'";
	stream << " must follow VALUE";

	errorCounter++;
	throw ParserException(true, stream.str(), startInstr, ++tmp);
}

void Parser::errorNotOpenScope()
{
	eToken	token = (*iter)->getToken();
	auto	tmp = iter;

	if (!optimizator || (optimizator && !(token == NumN || token == NumZ)))
	{
		if (prevState == 3)
			++iter;
		currState = 1;
		errorCounter++;
	}
	else
	{
		numberValue = (*iter)->getValue();
		++iter;
		warningCounter++;
	}

	throw ParserException(!optimizator, "Not open bracket after data type", startInstr, ++tmp);
}

void Parser::errorNotNumber()
{
	std::stringstream	stream;
	auto				tmp = iter;

	stream << "After operand type \'" << sOperandTypes[opType] << "\'";
	stream << " must follow NUMBER";

	errorCounter++;
	throw ParserException(true, stream.str(), startInstr, ++tmp);
}

void Parser::errorEmptyScopes()
{
	std::stringstream	stream;

	stream << "Detected empty brackets, you must add some NUMBER between them";

	errorCounter++;
	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorImplicitConversionNtoZ()
{
	std::stringstream	stream;
	auto				tmp = iter;

	iter++;

	if (!optimizator)
	{
		currState = 1;

		if ((*iter)->getToken() == CloseScope)
			iter++;
		errorCounter++;
	}
	else
		warningCounter++;

	stream << "Detected implicit conversion from integer type " <<
	"to floating point type \'" << sOperandTypes[opType] << "\'";


	throw ParserException(!optimizator, stream.str(), startInstr, ++tmp);
}

void Parser::errorImplicitConversionZtoN()
{
	std::stringstream	stream;
	auto				tmp = iter;

	iter++;

	if (!optimizator)
	{
		currState = 1;

		if ((*iter)->getToken() == CloseScope)
			iter++;
		errorCounter++;
	}
	else
		warningCounter++;

	stream << "Detected implicit conversion from floating point type " <<
	"to integer type \'" << sOperandTypes[opType] << "\'";

	throw ParserException(!optimizator, stream.str(), startInstr, ++tmp);
}

void Parser::errorNotCloseScope()
{
	std::stringstream	stream;
	auto				tmp = iter;

	stream << "You forgot close the brackets... Stupid";

	errorCounter++;
	throw ParserException(true, stream.str(), startInstr, ++tmp);
}

void Parser::errorNotEndLine()
{
	std::stringstream	stream;
	auto				tmp = iter;

	stream << "You forgot end line. Remember, one instruction on line";

	if (!optimizator)
		errorCounter++;
	else
		warningCounter++;

	throw ParserException(!optimizator, stream.str(), startInstr, ++tmp);
}

void Parser::errorUnknownInstruction()
{
	std::stringstream	stream;

	stream << "Detected undeclared instruction";

	errorCounter++;
	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorBadLogicPosition()
{
	std::stringstream	stream;

	stream << "Detected expression which destroying grammar logic of program";

	errorCounter++;
	throw ParserException(true, stream.str(), startInstr, ++iter);
}