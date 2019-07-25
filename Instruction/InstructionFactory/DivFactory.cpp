//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "DivFactory.hpp"
#include "../DivInstruction.hpp"

IInstruction* DivFactory::createInstruction(Fsm const &)
{
	return new DivInstruction();
}