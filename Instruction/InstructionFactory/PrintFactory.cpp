//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "PrintFactory.hpp"
#include "../PrintInstruction.hpp"

IInstruction* PrintFactory::createInstruction(Fsm const &)
{
	return new PrintInstruction();
}