//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#include "InstructionFactory.hpp"

InstructionFactory *InstructionFactory::factories[INSTR_COUNT] = {
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

		new MinFactory(),
		new MaxFactory(),
		new FrontFactory(),
		new BackFactory(),

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

AInstruction* AddFactory::createInstruction(const Parser &parser)
{
	return new AddInstruction(parser.getStartToken());
}

AInstruction* AssertFactory::createInstruction(const Parser &parser)
{
	return new AssertInstruction(parser.getStartToken(), parser.getOperandType(),
			parser.getNumValue());
}

AInstruction* DivFactory::createInstruction(const Parser &parser)
{
	return new DivInstruction(parser.getStartToken());
}

AInstruction* DumpFactory::createInstruction(const Parser &parser)
{
	return new DumpInstruction(parser.getStartToken());
}

AInstruction* ExitFactory::createInstruction(const Parser &parser)
{
	return new ExitInstruction(parser.getStartToken());
}

AInstruction* ModFactory::createInstruction(const Parser &parser)
{
	return new ModInstruction(parser.getStartToken());
}

AInstruction* MulFactory::createInstruction(const Parser &parser)
{
	return new MulInstruction(parser.getStartToken());
}

AInstruction* PopFactory::createInstruction(const Parser &parser)
{
	return new PopInstruction(parser.getStartToken());
}

AInstruction* PrintFactory::createInstruction(const Parser &parser)
{
	return new PrintInstruction(parser.getStartToken());
}

AInstruction* PushFactory::createInstruction(const Parser &parser)
{
	return new PushInstruction(parser.getStartToken(),parser.getOperandType(),
			parser.getNumValue());
}

AInstruction* SubFactory::createInstruction(const Parser &parser)
{
	return new SubInstruction(parser.getStartToken());
}

AInstruction* MinFactory::createInstruction(const Parser &parser)
{
	return new MinInstruction(parser.getStartToken());
}

AInstruction* MaxFactory::createInstruction(const Parser &parser)
{
	return new MaxInstruction(parser.getStartToken());
}

AInstruction* FrontFactory::createInstruction(const Parser &parser)
{
	return new FrontInstruction(parser.getStartToken());
}

AInstruction* BackFactory::createInstruction(const Parser &parser)
{
	return new BackInstruction(parser.getStartToken());
}