//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//
#include <map>
#include "Fsm.hpp"

bool	Fsm::zeroCond(char *c)
{
	return (*c == '\0');
}

bool Fsm::endLineCond(char *c)
{
	return (*c == '\n');
}

bool Fsm::commentCond(char *c)
{
	return (*c == ';');
}

bool Fsm::numberCond(char *c)
{
	return (isdigit(*c));
}

bool Fsm::whiteSpaceCondition(char *c)
{
	return (*c == '\t' || *c == ' ');
}

bool Fsm::minusCond(char *c)
{
	return (*c == '-');
}

bool Fsm::dotCond(char *c)
{
	return (*c == '.');
}

bool Fsm::openScopeCond(char *c)
{
	return (*c == '(');
}

bool Fsm::closeScopeCond(char *c)
{
	return (*c == ')');
}

bool Fsm::instructionCond(char *c)
{
	for (int i = 0; i < INSTR_COUNT; i++)
		if (sInstrutions[i].compare(carret, sInstrutions[i].size(), c) == 0)
		{
			tmpVar = i;
			return (true);
		}
	return (false);
}

bool Fsm::operandTypeCond(char *c)
{
	for (int i = 0; i < INSTR_COUNT; i++)
		if (sOperandTypes[i].compare(carret, sOperandTypes[i].size(), c) == 0)
		{
			tmpVar = i;
			return (true);
		}
	return (false);
}