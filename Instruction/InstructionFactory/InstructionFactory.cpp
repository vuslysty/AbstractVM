//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "InstructionFactory.hpp"
#include "../../Fsm additions/Fsm.hpp"
#include "../DivInstruction.hpp"
#include "../DumpInstruction.hpp"
#include "../AddInstruction.hpp"
#include "../AssertInstruction.hpp"
#include "../ExitInstruction.hpp"
#include "../ModInstruction.hpp"
#include "../MulInstruction.hpp"
#include "../PopInstruction.hpp"
#include "../PrintInstruction.hpp"
#include "../PushInstruction.hpp"
#include "../SubInstruction.hpp"


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

void InstructionFactory::delFactory()
{
	for (int i = Push; i <= Exit; i++)
		delete factories[i];
}

IInstruction* InstructionFactory::create(Fsm const &fsm)
{
	eInstruction instructionType = fsm.getInstructionType();

	return factories[instructionType]->createInstruction(fsm);
}

IInstruction* AddFactory::createInstruction(Fsm const &)
{
	return new AddInstruction();
}

IInstruction* AssertFactory::createInstruction(Fsm const &fsm)
{
	return new AssertInstruction(fsm.getOperandType(), fsm.getNumberInString());
}

IInstruction* DivFactory::createInstruction(Fsm const &)
{
	return new DivInstruction();
}

IInstruction* DumpFactory::createInstruction(Fsm const &)
{
	return new DumpInstruction();
}

IInstruction* ExitFactory::createInstruction(Fsm const &)
{
	return new ExitInstruction();
}

IInstruction* ModFactory::createInstruction(Fsm const &)
{
	return new ModInstruction();
}

IInstruction* MulFactory::createInstruction(Fsm const &)
{
	return new MulInstruction();
}

IInstruction* PopFactory::createInstruction(Fsm const &)
{
	return new PopInstruction();
}

IInstruction* PrintFactory::createInstruction(Fsm const &)
{
	return new PrintInstruction();
}

IInstruction* PushFactory::createInstruction(Fsm const &fsm)
{
	return new PushInstruction(fsm.getOperandType(), fsm.getNumberInString());
}

IInstruction* SubFactory::createInstruction(Fsm const &)
{
	return new SubInstruction();
}