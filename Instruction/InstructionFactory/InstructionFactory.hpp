//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_INSTRUCTIONFACTORY_HPP
#define ABSTRACTVM_INSTRUCTIONFACTORY_HPP


#include "../AInstruction.hpp"

class Fsm;

class InstructionFactory
{
private:

	static InstructionFactory	*factories[11];

protected:

	virtual AInstruction	*createInstruction(Fsm const &fsm) = 0;

public:

	virtual ~InstructionFactory() = default;

	static AInstruction	*create(Fsm const &fsm);

	static void delFactory();
};


class AddFactory : public InstructionFactory
{
public:
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class AssertFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class DivFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class DumpFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class ExitFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class ModFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class MulFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class PopFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class PrintFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class PushFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

class SubFactory : public InstructionFactory
{
	AInstruction	*createInstruction(Fsm const &fsm) final;
};

#endif //ABSTRACTVM_INSTRUCTIONFACTORY_HPP
