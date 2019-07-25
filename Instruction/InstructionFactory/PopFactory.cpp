//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "PopFactory.hpp"
#include "../PopInstruction.hpp"

IInstruction* PopFactory::createInstruction(Fsm const &fsm)
{
	return new PopInstruction();
}