//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"
#include "../ExceptionAVM.hpp"

void Lexer::identifierFS()
{
	std::string	identifier;

	identifier.assign(str, startToken, carret - startToken);

	moveCarretBack();

	for (int i = Push; i <= Assert; i++)
		if (sInstrutions[i] == identifier)
		{
			tokens.emplace_back(new Token(InstValue, identifier, row, startColumn));
			moveStartToken();
			return ;
		}

	for (int i = Pop; i <= Exit; i++)
		if (sInstrutions[i] == identifier)
		{
			tokens.emplace_back(new Token(InstEmpt, identifier, row, startColumn));
			moveStartToken();
			return ;
		}

	for (int i = Int8; i <= Double; i++)
		if (sOperandTypes[i] == identifier)
		{
			tokens.emplace_back(new Token(OperandType, identifier, row, startColumn));
			moveStartToken();
			return ;
		}

	workBeforeException();
	throw ExceptionAVM::UnknownInstruction();
}

void Lexer::openScopeFS()
{
	std::string	scope;

	scope.assign(str, startToken, 1);

	tokens.emplace_back(new Token(OpenScope, scope, row, startColumn));
	moveStartToken();
}

void Lexer::closeScopeFS()
{
	std::string	scope;

	scope.assign(str, startToken, 1);
	tokens.emplace_back(new Token(CloseScope, scope, row, startColumn));
	moveStartToken();
}

void Lexer::numNFS()
{
	std::string	num;


	num.assign(str, startToken, carret - startToken);
	moveCarretBack();

	tokens.emplace_back(new Token(NumN, num, row, startColumn));
	moveStartToken();
}

void Lexer::numZFS()
{
	std::string	num;


	num.assign(str, startToken, carret - startToken);
	moveCarretBack();

	tokens.emplace_back(new Token(NumZ, num, row, startColumn));
	moveStartToken();
}

void Lexer::endLineFS()
{
	std::string	endLine;

//	endLine.assign(str, carret, 1);
	endLine = "\\n";

	if (!tokens.empty() && tokens.back()->getToken() != EndLine)
		tokens.emplace_back(new Token(EndLine, endLine, row, col));

	countEndLines();
	moveStartToken();
}

void Lexer::endFS()
{
	std::string	end;

	stop = true;
	end.assign(str, carret, 1);
	end = "\\0";

	tokens.emplace_back(new Token(End, end, row, col));
	moveStartToken();
}

void Lexer::moveStartToken()
{
	startToken = carret + 1;
	startColumn = col + 1;
}

void Lexer::moveCarretBack()
{
	carret -= 1;
	col -= 1;
}

void Lexer::countEndLines()
{
	row++;
	col = 0; // after increment in main cycle it will be 1
}

void Lexer::workBeforeException()
{
	carret++;
	col++;
	startToken = carret;
	startColumn = col;
}