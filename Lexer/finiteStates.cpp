//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../ExceptionAVM.hpp"

void Lexer::identifierFS()
{
	std::string	identifier;


	identifier.assign(str, startToken, carret - startToken);

	startToken = carret;

	carret -= 1;

	for (int i = Push; i <= Assert; i++)
		if (sInstrutions[i] == identifier)
		{
			tokens.emplace_back(InstValue, identifier, row, col);
			return ;
		}

	for (int i = Pop; i <= Exit; i++)
		if (sInstrutions[i] == identifier)
		{
			tokens.emplace_back(InstEmpt, identifier, row, col);
			return ;
		}

	for (int i = Int8; i <= Double; i++)
		if (sOperandTypes[i] == identifier)
		{
			tokens.emplace_back(OperandType, identifier, row, col);
			return ;
		}

	throw ExceptionAVM::UnknownInstruction();
}

void Lexer::openScopeFS()
{
	std::string	scope;

	scope.assign(str, startToken, 1);
	startToken = carret + 1;

	tokens.emplace_back(Token(OpenScope, scope, row, col));
}

void Lexer::closeScopeFS()
{
	std::string	scope;


	scope.assign(str, startToken, 1);
	startToken = carret + 1;

	tokens.emplace_back(Token(CloseScope, scope, row, col));
}

void Lexer::numNFS()
{
	std::string	num;


	num.assign(str, startToken, carret - startToken);
	startToken = carret;
	carret -= 1;

	tokens.emplace_back(Token(NumN, num, row, col));
}

void Lexer::numZFS()
{
	std::string	num;


	num.assign(str, startToken, carret - startToken);
	startToken = carret;
	carret -= 1;

	tokens.emplace_back(Token(NumZ, num, row, col));
}

void Lexer::endLineFS()
{
	std::string	endLine;

	countEndLines();

	endLine.assign(str, carret, 1);
	startToken = carret + 1;

	tokens.emplace_back(Token(EndLine, endLine, row, col));
}

void Lexer::endFS()
{
	std::string	end;

	stop = true;
	end.assign(str, carret, 1);
	startToken = carret + 1;

	tokens.emplace_back(Token(End, end, row, col));
}

void Lexer::moveStartToken()
{
	startToken = carret + 1;
}

void Lexer::countEndLines()
{
	row++;
	col = 0; // after increment in main cycle it will be 1
}