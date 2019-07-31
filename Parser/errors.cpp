//
// Created by Vladyslav USLYSTYI on 2019-07-30.
//

#include <sstream>
#include "Parser.hpp"
#include "../Exceptions/ExceptionAVM.hpp"

void Parser::errorNotValue()
{
	std::stringstream	stream;

	stream << "After instruction \'" << sInstrutions[getInstructionType()] << "\'";
	stream << " must follow VALUE";

	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorNotOpenScope()
{

}

void Parser::errorNotNumber()
{
	std::stringstream	stream;

	stream << "After operand type \'" << sOperandTypes[opType] << "\'";
	stream << " must follow NUMBER";

	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorEmptyScopes()
{
	std::stringstream	stream;

	stream << "Empty scopes expected, you must add some NUMBER between them";

	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorImplicitConversionNtoZ()
{
	std::stringstream	stream;

	if (!optimizator)
		state = 1;

	stream << "expected implicit conversion from integer type " <<
	"to floating point type \'" << sOperandTypes[opType] << "\'";

	throw ParserException(!optimizator, stream.str(), startInstr, ++iter);
}

void Parser::errorImplicitConversionZtoN()
{
	std::stringstream	stream;

	if (!optimizator)
		state = 1;

	stream << "expected implicit conversion from floating point type " <<
	"to integer type \'" << sOperandTypes[opType] << "\'";

	throw ParserException(!optimizator, stream.str(), startInstr, ++iter);
}

void Parser::errorNotCloseScope()
{
	std::stringstream	stream;

	stream << "You forgot close scope... Stupid";

	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorNotEndLine()
{
	std::stringstream	stream;

	stream << "You forgot end line. Remember that one instruction - one line";

	throw ParserException(!optimizator, stream.str(), startInstr, ++iter);
}

void Parser::errorUnknownInstruction()
{
	std::stringstream	stream;

	stream << "Expected undeclared instruction";

	throw ParserException(true, stream.str(), startInstr, ++iter);
}

void Parser::errorBadLogicPosition()
{
	std::stringstream	stream;

	stream << "Expected expression which destroying grammar logic of program";

	throw ParserException(true, stream.str(), startInstr, ++iter);
}

bool inline isInstruction(eToken token)
{
	if (token == InstValue || token == InstBad || token == InstEmpt)
		return (true);
	else
		return (false);
}

void Parser::warningUnusedInstructions()
{
	if (isUnusedInstructions == false)
	{
		std::deque<Token *>::iterator tmp = iter;

		tmp++;

		while (tmp != endIter)
		{
			if (isInstruction((*tmp)->getToken()))
			{
				std::stringstream	stream;

				tmp = iter;
				tmp++;

				stream << "No one instruction from that position will be executed";

				throw ParserException(true, stream.str(), startInstr, ++iter);
			}
			tmp++;
		}
		isUnusedInstructions = true;
	}
}