//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include "Lexer.hpp"
#include "../Exceptions/ExceptionAVM.hpp"

Lexer::Lexer(std::string const &src, std::deque<Token *> &toks) :
		tokens(toks), errorCount(0), stop(false), row(1), col(1), carret(0),
		startToken(0), startColumn(1), startRow(1)
{
	str = src;
}

Lexer::Lexer(Lexer const &src) : tokens(src.tokens)
{
	*this = src;
}

Lexer& Lexer::operator=(Lexer const &rhs)
{
	if (this != &rhs)
	{
		this->state = rhs.state;
		this->errorCount = rhs.errorCount;
		this->stop = rhs.stop;
		this->row = rhs.row;
		this->col = rhs.col;
		this->carret = rhs.carret;
		this->startToken = rhs.startToken;
		this->startColumn = rhs.startColumn;
		this->startRow = rhs.startRow;
		this->startTokenTMP = rhs.startTokenTMP;
		this->startColumnTMP = rhs.startColumnTMP;
		this->str = rhs.str;
	}
	return *this;
}

Lexer::~Lexer() {}

std::deque<Token *> &Lexer::getTokens()
{
	return tokens;
}

int Lexer::getCondition() const
{
	int i;

	for (i = 0; i < CONDITION_COUNT; i++)
		if ((this->*conditions[i])(str[carret]))
			break ;
	return (i);
}

void Lexer::doLexAnalization()
{
	transitionL_callback	funk = nullptr;
	int 					condition = 0;

	state = 1;
	while (!stop)
	{
		condition = getCondition();
		funk = fsmTable[state - 1][condition].worker;

		if (funk)
			(this->*funk)();

		state = fsmTable[state - 1][condition].newState;

		carret++;
		col++;
	}
}

bool Lexer::isWork() const
{
	return (!stop);
}

unsigned int Lexer::getErrorCount() const
{
	return errorCount;
}

Conditions	Lexer::conditions[CONDITION_COUNT] = {
		&Lexer::alphaCondition,
		&Lexer::numCondition,
		&Lexer::endLineCondition,
		&Lexer::minusCondition,
		&Lexer::whiteCondition,
		&Lexer::dotCondition,
		&Lexer::commentCondition,
		&Lexer::openScopeCondition,
		&Lexer::closeScopeCondition,
		&Lexer::zeroCondition,
		&Lexer::slashCondition
};

const transitionL	Lexer::fsmTable[10][12] = {
//-------------------- STATE 1 ----------------------------------------
		[0][0] = {2, nullptr},
		[0][1] = {4, nullptr},
		[0][2] = {1, &Lexer::endLineFS},
		[0][3] = {3, nullptr},
		[0][4] = {1, &Lexer::moveStartToken},
		[0][5] = {1, &Lexer::errorIdent},
		[0][6] = {7, nullptr},
		[0][7] = {1, &Lexer::openScopeFS},
		[0][8] = {1, &Lexer::closeScopeFS},
		[0][9] = {1, &Lexer::endFS},
		[0][10] = {8, nullptr},
		[0][11] = {1, &Lexer::errorIdent},
//-------------------- STATE 2 ----------------------------------------
		[1][0 ... 1] = {2, nullptr},
		[1][2 ... 11] = {1, &Lexer::identifierFS},
//-------------------- STATE 3 ----------------------------------------
		[2][0] = {1, &Lexer::errorMinus},
		[2][2 ... 11] = {1, &Lexer::errorMinus},
		[2][1] = {4, nullptr},
//-------------------- STATE 4 ----------------------------------------
		[3][0] = {1, &Lexer::numNFS},
		[3][1] = {4, nullptr},
		[3][2 ... 4] = {1, &Lexer::numNFS},
		[3][5] = {5, nullptr},
		[3][6 ... 11] = {1, &Lexer::numNFS},
//-------------------- STATE 5 ----------------------------------------
		[4][0] = {1, &Lexer::errorDot},
		[4][1] = {6, nullptr},
		[4][2 ... 11] = {1, &Lexer::errorDot},
//-------------------- STATE 6 ----------------------------------------
		[5][0] = {1, &Lexer::numZFS},
		[5][1] = {6, nullptr},
		[5][2 ... 11] = {1, &Lexer::numZFS},
//-------------------- STATE 7 ----------------------------------------
		[6][0 ... 1] = {7, nullptr},
		[6][2] = {1, &Lexer::endLineFS},
		[6][3 ... 8] = {7, nullptr},
		[6][9] = {1, &Lexer::endFS},
		[6][10 ... 11] = {7, nullptr},
//-------------------- STATE 8 ----------------------------------------
		[7][0 ... 5] = {1, &Lexer::errorMultilineComment},
		[7][6] = {9, nullptr},
		[7][7 ... 11] = {1, &Lexer::errorMultilineComment},
//-------------------- STATE 9 ----------------------------------------
		[8][0 ... 1] = {9, nullptr},
		[8][2] = {9, &Lexer::countEndLines},
		[8][3 ... 5] = {9, nullptr},
		[8][6] = {10, nullptr},
		[8][7 ... 8] = {9, nullptr},
		[8][9] = {1, &Lexer::errorMultilineComment},
		[8][10 ... 11] = {9, nullptr},
//-------------------- STATE 10 ---------------------------------------
		[9][0 ... 1] = {9, nullptr},
		[9][2] = {9, &Lexer::countEndLines},
		[9][3 ... 5] = {9, nullptr},
		[9][6] = {10, nullptr},
		[9][7 ... 8] = {9, nullptr},
		[9][9] = {1, &Lexer::errorMultilineComment},
		[9][10] = {1, &Lexer::moveStartToken},
		[9][11] = {9, nullptr}
};