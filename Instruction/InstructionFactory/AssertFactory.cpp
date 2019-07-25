//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "AssertFactory.hpp"
#include "../AssertInstruction.hpp"

IInstruction* AssertFactory::createInstruction(Fsm const &fsm)
{
	return new AssertInstruction();
}