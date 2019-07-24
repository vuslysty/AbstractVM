//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Fsm.hpp"

void Fsm::checkInstruction()
{
	if (flags.instruction)
	{
		flags.error = true;
		currState = 11;
		return ;
	}

	flags.instruction = true;
	instruction = static_cast<eInstruction >(tmpVar);

	carret += sInstrutions[instruction].size() - 1;

	if (instruction != Push && instruction != Assert)
		currState = 1;
}

void Fsm::checkOperandType()
{
	flags.operandType = true;
	operandType = static_cast<eOperandType >(tmpVar);

	carret += sOperandTypes[operandType].size() - 1;
}

void Fsm::beginOfNumber()
{
	beginNum = carret;
}

void Fsm::endOfNumberN()
{
	endNum = carret;
	flags.number = true;
	numberType = N;
}

void Fsm::endOfNumberZ()
{
	endNum = carret;
	flags.number = true;
	numberType = Z;
}

void Fsm::changeInstruction()
{
	rowNum++;

	if (str[carret] == Zero)
		flags.stop = true;

	if (flags.error)
		instructionQueue.push(new )
}