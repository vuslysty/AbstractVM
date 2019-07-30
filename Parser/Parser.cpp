//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#include "Parser.hpp"

const transitionP	Parser::fsmTable[8][10] = {
//-------------------- STATE 1 ----------------------------------------
		[0][0] = {8, nullptr},
		[0][1] = {2, nullptr},
		[0][2] = {1, &Parser::errorUnknownInstruction},
		[0][3 ... 7] = {1, &Parser::errorBadLogicPosition},
		[0][8] = {1, nullptr},
		[0][9] = {1, &Parser::FSstop},

//-------------------- STATE 2 ----------------------------------------
		[1][0 ... 2] = {1, &Parser::errorNotValue},
		[1][3] = {3, &Parser::saveOperandType},
		[1][4 ... 9] = {1, &Parser::errorNotValue},

//-------------------- STATE 3 ----------------------------------------
		[2][0 ... 3] = {1, &Parser::errorNotOpenScope},
		[2][4] = {4, nullptr},
		[2][5] = {1, &Parser::errorNotOpenScope},
		[2][6 ... 7] = {7, &Parser::numberState},
		[2][8 ... 9] = {1, &Parser::errorNotOpenScope},

//-------------------- STATE 4 ----------------------------------------
		[3][0 ... 4] = {1, &Parser::errorNotNumber},
		[3][5] = {1, &Parser::errorEmptyScopes},
		[3][6 ... 7] = {5, &Parser::numberState},
		[3][8 ... 9] = {1, &Parser::errorNotNumber},

//-------------------- STATE 5 ----------------------------------------
		[4][0 ... 4] = {1, &Parser::errorNotCloseScope},
		[4][5] = {6, nullptr},
		[4][6 ... 9] = {1, &Parser::errorNotCloseScope},

//-------------------- STATE 6 ----------------------------------------
		[5][0 ... 1] = {1, &Parser::FSoptimizatedEndLine},
		[5][2 ... 7] = {1, &Parser::errorNotEndLine},
		[5][8 ... 9] = {1, &Parser::FSnormalInstValue},

//-------------------- STATE 7 ----------------------------------------
		[6][0 ... 1] = {1, &Parser::FSoptimizatedEndLine},
		[6][2 ... 7] = {1, &Parser::errorNotEndLine},
		[6][8 ... 9] = {1, &Parser::FSoptimizatedInstValue},

//-------------------- STATE 8 ----------------------------------------
		[7][0 ... 1] = {1, &Parser::FSoptimizatedEndLine},
		[7][2 ... 7] = {1, &Parser::errorNotEndLine},
		[7][8 ... 9] = {1, &Parser::FSInstEmpt}
};