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

AInstruction* InstructionFactory::create(Parser const &parser)
{
	eInstruction instructionType = parser.getInstructionType();

	return factories[instructionType]->createInstruction(parser);
}

AInstruction* AddFactory::createInstruction(const Parser &)
{
	return new AddInstruction();
}

AInstruction* AssertFactory::createInstruction(const Parser &parser)
{
	return new AssertInstruction(parser.getOperandType(), parser.getNumValue());
}

AInstruction* DivFactory::createInstruction(const Parser &)
{
	return new DivInstruction();
}

AInstruction* DumpFactory::createInstruction(const Parser &)
{
	return new DumpInstruction();
}

AInstruction* ExitFactory::createInstruction(const Parser &)
{
	return new ExitInstruction();
}

AInstruction* ModFactory::createInstruction(const Parser &)
{
	return new ModInstruction();
}

AInstruction* MulFactory::createInstruction(const Parser &)
{
	return new MulInstruction();
}

AInstruction* PopFactory::createInstruction(const Parser &)
{
	return new PopInstruction();
}

AInstruction* PrintFactory::createInstruction(const Parser &)
{
	return new PrintInstruction();
}

AInstruction* PushFactory::createInstruction(const Parser &parser)
{
	return new AssertInstruction(parser.getOperandType(), parser.getNumValue());
}

AInstruction* SubFactory::createInstruction(const Parser &)
{
	return new SubInstruction();
}