//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Instruction.hpp"
#include "AddInstruction.hpp"
#include "DumpInstruction.hpp"
#include "PopInstruction.hpp"
#include "SubInstruction.hpp"
#include "MulInstruction.hpp"
#include "DivInstruction.hpp"
#include "ModInstruction.hpp"
#include "PrintInstruction.hpp"
#include "ExitInstruction.hpp"
#include "PushInstruction.hpp"
#include "AssertInstruction.hpp"

Instruction::Instruction() {}
Instruction::Instruction(int line) : line(line) {}
Instruction::Instruction(Instruction const &) {}
Instruction& Instruction::operator=(Instruction const &) {return *this}
Instruction::~Instruction() {}

void Instruction::doInstruction(std::deque<IOperand> &)
{
//	throw EXCEPTION InvalidInstruction
}

Instruction* Instruction::createInstruction(int line)
{
	return new Instruction(line);
}

Instruction* Instruction::createInstruction(eInstruction instruction, int line)
{
	switch(instruction)
	{
		case Push: return new PushInstruction(Int32, "0", N, line);
		case Assert: return new AssertInstruction(Int32, "0", N, line);
		case Pop: return new PopInstruction(line);
		case Dump: return new DumpInstruction(line);
		case Add: return new AddInstruction(line);
		case Sub: return new SubInstruction(line);
		case Mul: return new MulInstruction(line);
		case Div: return new DivInstruction(line);
		case Mod: return new ModInstruction(line);
		case Print: return new PrintInstruction(line);
		case Exit: return new ExitInstruction(line);
	}
}

Instruction* Instruction::createInstruction(eInstruction instruction,
		eOperandType opType, eNumberType numType, std::string num, int line)
{
	if (instruction != Push && instruction != Assert)
		createInstruction(instruction);

	switch(instruction)
	{
		case Push: return new PushInstruction(opType, num, numType, line);
		case Assert: return new AssertInstruction(opType, num, numType, line);
		default: break;
	}
}