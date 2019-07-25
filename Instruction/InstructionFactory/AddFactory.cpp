//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "AddFactory.hpp"

IInstruction* AddFactory::createInstruction(Fsm const &)
{
	return new AddInstruction();
}