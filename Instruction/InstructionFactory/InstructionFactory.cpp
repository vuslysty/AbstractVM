//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "InstructionFactory.hpp"
#include "AddFactory.hpp"
#include "PushFactory.hpp"
#include "AssertFactory.hpp"
#include "PopFactory.hpp"
#include "DumpFactory.hpp"
#include "SubFactory.hpp"
#include "DivFactory.hpp"
#include "ModFactory.hpp"
#include "MulFactory.hpp"
#include "PrintFactory.hpp"
#include "ExitFactory.hpp"

InstructionFactory *InstructionFactory::factories[11] = {
		new PushFactory(),
		new AssertFactory(),
		new PopFactory(),
		new DumpFactory(),
		new AddFactory(),
		new SubFactory(),
		new MulFactory(),
		new DivFactory(),
		new ModFactory(),
		new PrintFactory(),
		new ExitFactory()
};

IInstruction* InstructionFactory::createInstruction(Fsm const &fsm)
{
	eInstruction instructionType = fsm.getInstructionType();

	return factories[instructionType]->createInstruction(fsm);
}