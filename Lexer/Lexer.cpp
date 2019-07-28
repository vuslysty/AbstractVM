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

	for (i = 0; i < 10; i++) // We hahe 10 conditions
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

Conditions	Lexer::conditions[10] = {
		&Lexer::alphaCondition,
		&Lexer::numCondition,
		&Lexer::endLineCondition,
		&Lexer::minusCondition,
		&Lexer::whiteCondition,
		&Lexer::dotCondition,
		&Lexer::commentCondition,
		&Lexer::openScopeCondition,
		&Lexer::closeScopeCondition,
		&Lexer::zeroCondition
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

const transition	Lexer::fsmTable[7][11] = {
		[0][0] = {2, nullptr},
		[0][1] = {4, nullptr},
		[0][2] = {1, &Lexer::endLineFS},
		[0][3] = {3, nullptr},
		[0][4] = {1, &Lexer::whiteFS},
		[0][5] = {1, &Lexer::errorIdent},
		[0][6] = {7, nullptr},
		[0][7] = {1, &Lexer::openScopeFS},
		[0][8] = {1, &Lexer::closeScopeFS},
		[0][9] = {1, &Lexer::endFS},
		[0][10] = {1, &Lexer::errorIdent},

		[1][0 ... 1] = {2, nullptr},
		[1][2 ... 10] = {1, &Lexer::identifierFS},

		[2][0] = {1, &Lexer::errorMinus},
		[2][2 ... 10] = {1, &Lexer::errorMinus},
		[2][1] = {4, nullptr},

		[3][0] = {1, &Lexer::numNFS},
		[3][1] = {4, nullptr},
		[3][2 ... 4] = {1, &Lexer::numNFS},
		[3][5] = {5, nullptr},
		[3][6 ... 10] = {1, &Lexer::numNFS},

		[4][0] = {1, &Lexer::errorDot},
		[4][1] = {6, nullptr},
		[4][2 ... 10] = {1, &Lexer::errorDot},

		[5][0] = {1, &Lexer::numZFS},
		[5][1] = {6, nullptr},
		[5][2 ... 10] = {1, &Lexer::numZFS},

		[6][0 ... 1] = {7, nullptr},
		[6][2] = {1, &Lexer::endLineFS},
		[6][3 ... 8] = {7, nullptr},
		[6][9] = {1, &Lexer::endFS},
		[6][10] = {7, nullptr}
};