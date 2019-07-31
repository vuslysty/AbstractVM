//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_INSTRUCTIONFACTORY_HPP
#define ABSTRACTVM_INSTRUCTIONFACTORY_HPP


#include "../AInstruction.hpp"
#include "../../Parser/Parser.hpp"

class InstructionFactory
{
private:

	static InstructionFactory	*factories[11];

protected:

	virtual AInstruction	*createInstruction(const Parser &parser) = 0;

public:

	virtual ~InstructionFactory() = default;

	static AInstruction	*create(Parser const &);

	static void delFactory();
};


class AddFactory : public InstructionFactory
{
public:
	AInstruction	*createInstruction(const Parser &parser) final;
};

class AssertFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class DivFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class DumpFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class ExitFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class ModFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class MulFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class PopFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class PrintFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class PushFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

class SubFactory : public InstructionFactory
{
	AInstruction	*createInstruction(const Parser &parser) final;
};

#endif //ABSTRACTVM_INSTRUCTIONFACTORY_HPP
