//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "InstructionFactory.hpp"

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

AInstruction* InstructionFactory::create(Fsm const &)
{
//	eInstruction instructionType = fsm.getInstructionType();

//	return factories[instructionType]->createInstruction(fsm);
	return (nullptr);
}

AInstruction* AddFactory::createInstruction(Fsm const &)
{
	return new AddInstruction();
}

AInstruction* AssertFactory::createInstruction(Fsm const &)
{
	return (nullptr);
//	return new AssertInstruction(fsm.getOperandType(), fsm.getNumberInString());
}

AInstruction* DivFactory::createInstruction(Fsm const &)
{
	return new DivInstruction();
}

AInstruction* DumpFactory::createInstruction(Fsm const &)
{
	return new DumpInstruction();
}

AInstruction* ExitFactory::createInstruction(Fsm const &)
{
	return new ExitInstruction();
}

AInstruction* ModFactory::createInstruction(Fsm const &)
{
	return new ModInstruction();
}

AInstruction* MulFactory::createInstruction(Fsm const &)
{
	return new MulInstruction();
}

AInstruction* PopFactory::createInstruction(Fsm const &)
{
	return new PopInstruction();
}

AInstruction* PrintFactory::createInstruction(Fsm const &)
{
	return new PrintInstruction();
}

AInstruction* PushFactory::createInstruction(Fsm const &)
{
	return (nullptr);
//	return new PushInstruction(fsm.getOperandType(), fsm.getNumberInString());
}

AInstruction* SubFactory::createInstruction(Fsm const &)
{
	return new SubInstruction();
}