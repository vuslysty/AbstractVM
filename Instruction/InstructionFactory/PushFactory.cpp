//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "PushFactory.hpp"
#include "../PushInstruction.hpp"
#include "../AssertInstruction.hpp"
#include "../../Fsm additions/Fsm.hpp"

IInstruction* PushFactory::createInstruction(Fsm const &fsm)
{
	return new PushInstruction(fsm.getOperandType(), fsm.getNumberInString());
}