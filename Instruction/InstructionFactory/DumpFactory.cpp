//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "DumpFactory.hpp"
#include "../DumpInstruction.hpp"

IInstruction* DumpFactory::createInstruction(Fsm const &)
{
	return new DumpInstruction();
}