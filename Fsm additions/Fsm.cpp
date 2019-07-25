//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Fsm.hpp"

const std::string Fsm::sInstrutions[INSTR_COUNT] = {
		"push", "assert", "pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"
};

const std::string Fsm::sOperandTypes[OPER_TYPE_COUNT] = {
		"int8", "int16", "int32", "float", "double"
};

void Fsm::doFsm()
{
	int	currState = 1;

	while (1)
	{
		if (stopFlag)
			break ;

	}
}

eInstruction Fsm::getInstructionType() const
{
	return (instruction);
}

eOperandType Fsm::getOperandType() const
{
	return operandType;
}

eNumberType Fsm::getNumberType() const
{
	return numberType;
}

std::string Fsm::getNumberInString() const
{
	std::string		number;
	return number.assign(str, beginNum, endNum - beginNum + 1);
}