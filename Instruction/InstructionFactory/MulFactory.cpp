//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "MulFactory.hpp"
#include "../MulInstruction.hpp"

IInstruction* MulFactory::createInstruction(Fsm const &)
{
	return new MulInstruction();
}