//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#include "Lexer.hpp"

Lexer::Lexer() : row(1), col(1), stop(false), carret(0), startToken(0)
{}

Lexer::Lexer(std::string const &str) : Lexer()
{
	this->str = str;
	startLexAnalization();
}

Lexer::Lexer(Lexer const &src)
{
	*this = src;
}

Lexer& Lexer::operator=(Lexer const &rhs)
{
	if (this != &rhs)
	{
		this->row = rhs.row;
		this->col = rhs.col;

		this->stop = rhs.stop;

		this->carret = rhs.carret;

		this->str = rhs.str;
		this->startToken = rhs.startToken;
		this->tokens = rhs.tokens;
	}
	return *this;
}

Lexer::~Lexer() {}

std::deque<Token> Lexer::getTokens() const
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

void Lexer::startLexAnalization()
{
	transition_callback	funk = nullptr;
	int 				state = 1;
	int 				condition = 0;

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
//
//FiniteStates	Lexer::finiteStates[7] = {
//		&Lexer::identifierFS,
//		&Lexer::openScopeFS,
//		&Lexer::closeScopeFS,
//		&Lexer::numNFS,
//		&Lexer::numZFS,
//		&Lexer::endLineFS,
//		&Lexer::endFS
//};
//
//Errors	Lexer::errors[3] = {
//		&Lexer::errorMinus,
//		&Lexer::errorDot,
//		&Lexer::errorIdent
//};

const transition	Lexer::fsmTable[10][12] = {
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
		[0][10] = {1, &Lexer::errorIdent},
		[0][11] = {8, nullptr},
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
		[7][0 ... 5] = {1, &Lexer::errorIdent},
		[7][6] = {9, nullptr},
		[7][7 ... 11] = {1, &Lexer::errorIdent},
//-------------------- STATE 9 ----------------------------------------
		[8][0 ... 1] = {9, nullptr},
		[8][2] = {9, &Lexer::countEndLines},
		[8][3 ... 5] = {9, nullptr},
		[8][6] = {10, nullptr},
		[8][7 ... 8] = {9, nullptr},
		[8][9] = {1, &Lexer::errorMultilineComment},
		[8][10 ... 11] = {9, nullptr},
//-------------------- STATE 10 ---------------------------------------
		[9][0 ... 5] = {9, nullptr},
		[9][6] = {10, nullptr},
		[9][7 ... 8] = {9, nullptr},
		[9][9] = {1, &Lexer::errorMultilineComment},
		[9][10] = {9, nullptr},
		[9][11] = {1, &Lexer::moveStartToken}
};