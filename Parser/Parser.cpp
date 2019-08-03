//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#include "Parser.hpp"

Parser::Parser(std::deque<Token *> *tokens, std::queue<AInstruction* > &inst) :
		instructions(inst),
		fullErrorOutput(false), optimizator(false), errorCounter(0),
		warningCounter(0), currState(1), prevState(1)
{
	iter = tokens->begin();
	endIter = tokens->end();
}

eInstruction Parser::getInstructionType() const
{
	std::string	instruction = (*startInstr)->getValue();

	for (int i = 0; i < INSTR_COUNT; i++)
		if (sInstrutions[i] == instruction)
			return (static_cast<eInstruction >(i));
	return (Exit);
}

eOperandType Parser::getOperandType() const
{
	return opType;
}

std::string Parser::getNumValue() const
{
	return numberValue;
}

Token* Parser::getStartToken() const
{
	return *startInstr;
}

std::queue<AInstruction* > &Parser::getInstructions()
{
	return instructions;
}

bool Parser::isWork() const
{
	return (iter != endIter);
}

unsigned int Parser::getErrorCount() const
{
	return errorCounter;
}

unsigned int Parser::getWarningCount() const
{
	return warningCounter;
}

void Parser::doParsAnalization()
{
	transitionP_callback	funk = nullptr;
	int 					condition = 0;

	while (iter != endIter)
	{
		if (currState == 1)
			startInstr = iter;

		condition = getCondition();

		prevState = currState;
		funk = fsmTable[currState - 1][condition].worker;
		currState = fsmTable[currState - 1][condition].newState;

		if (funk)
			(this->*funk)();

		iter++;
	}
}

void Parser::setOptimizator(bool optimization)
{
	optimizator = optimization;
}


const transitionP	Parser::fsmTable[8][10] = {
//-------------------- STATE 1 ----------------------------------------
		[0][0] = {8, nullptr},
		[0][1] = {2, nullptr},
		[0][2] = {1, &Parser::errorUnknownInstruction},
		[0][3 ... 7] = {1, &Parser::errorBadLogicPosition},
		[0][8] = {1, nullptr},
		[0][9] = {1, nullptr},

//-------------------- STATE 2 ----------------------------------------
		[1][0 ... 2] = {1, &Parser::errorNotValue},
		[1][3] = {3, &Parser::saveOperandType},
		[1][4 ... 9] = {1, &Parser::errorNotValue},

//-------------------- STATE 3 ----------------------------------------
		[2][0 ... 3] = {1, &Parser::errorNotOpenScope},
		[2][4] = {4, nullptr},
		[2][5] = {1, &Parser::errorNotOpenScope},
		[2][6 ... 7] = {7, &Parser::errorNotOpenScope},
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
		[5][8 ... 9] = {1, &Parser::FSaddInstruction},

//-------------------- STATE 7 ----------------------------------------
		[6][0 ... 1] = {1, &Parser::FSoptimizatedEndLine},
		[6][2 ... 7] = {1, &Parser::errorNotEndLine},
		[6][8 ... 9] = {1, &Parser::FSaddInstruction},

//-------------------- STATE 8 ----------------------------------------
		[7][0 ... 1] = {1, &Parser::FSoptimizatedEndLine},
		[7][2 ... 7] = {1, &Parser::errorNotEndLine},
		[7][8 ... 9] = {1, &Parser::FSaddInstruction}
};