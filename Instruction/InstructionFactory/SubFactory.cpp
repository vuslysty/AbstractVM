//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "SubFactory.hpp"
#include "../SubInstruction.hpp"

IInstruction* SubFactory::createInstruction(Fsm const &fsm)
{
	return new SubInstruction();
}