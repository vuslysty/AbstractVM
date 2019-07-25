//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "ModFactory.hpp"
#include "../ModInstruction.hpp"

IInstruction* ModFactory::createInstruction(Fsm const &)
{
	return new ModInstruction();
}