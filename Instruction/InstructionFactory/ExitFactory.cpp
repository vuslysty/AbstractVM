//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "ExitFactory.hpp"
#include "../ExitInstruction.hpp"

IInstruction* ExitFactory::createInstruction(Fsm const &)
{
	return new ExitInstruction();
}