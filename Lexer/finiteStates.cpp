//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../ExceptionAVM.hpp"

void Lexer::identifierFS()
{
	std::string	identifier;


	identifier.assign(str, startToken, carret - startToken);

	carret -= 1;
	col -= 1;

	for (int i = Push; i <= Assert; i++)
		if (sInstrutions[i] == identifier)
		{
			tokens.emplace_back(new Token(InstValue, identifier, row, col - identifier.size() + 1));
			startToken = carret + 1;
			return ;
		}

	for (int i = Pop; i <= Exit; i++)
		if (sInstrutions[i] == identifier)
		{
			tokens.emplace_back(new Token(InstEmpt, identifier, row, col - identifier.size() + 1));
			startToken = carret + 1;
			return ;
		}

	for (int i = Int8; i <= Double; i++)
		if (sOperandTypes[i] == identifier)
		{
			tokens.emplace_back(new Token(OperandType, identifier, row, col - identifier.size() + 1));
			startToken = carret + 1;
			return ;
		}

	throw ExceptionAVM::UnknownInstruction();
}

void Lexer::openScopeFS()
{
	std::string	scope;

	scope.assign(str, startToken, 1);

	tokens.emplace_back(new Token(OpenScope, scope, row, col));
	startToken = carret + 1;
}

void Lexer::closeScopeFS()
{
	std::string	scope;

	scope.assign(str, startToken, 1);
	tokens.emplace_back(new Token(CloseScope, scope, row, col));
	startToken = carret + 1;
}

void Lexer::numNFS()
{
	std::string	num;


	num.assign(str, startToken, carret - startToken);
	carret -= 1;
	col -= 1;

	tokens.emplace_back(new Token(NumN, num, row, col - num.size() + 1));
	startToken = carret + 1;
}

void Lexer::numZFS()
{
	std::string	num;


	num.assign(str, startToken, carret - startToken);
	carret -= 1;
	col -= 1;

	tokens.emplace_back(new Token(NumZ, num, row, col - num.size() + 1));
	startToken = carret + 1;
}

void Lexer::endLineFS()
{
	std::string	endLine;

//	endLine.assign(str, carret, 1);
	endLine = "\\n";

	if (!tokens.empty() && tokens.back()->getToken() != EndLine)
		tokens.emplace_back(new Token(EndLine, endLine, row, col));

	countEndLines();
	startToken = carret + 1;
}

void Lexer::endFS()
{
	std::string	end;

	stop = true;
	end.assign(str, carret, 1);
	end = "\\0";

	tokens.emplace_back(new Token(End, end, row, col));
	startToken = carret + 1;
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