//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_AINSTRUCTION_HPP
#define ABSTRACTVM_AINSTRUCTION_HPP


#include <deque>
#include "../AVM.hpp"
//#include "../Fsm additions/Fsm.hpp"

class IOperand;

class AInstruction
{
public:

	virtual	void doInstruction(std::deque<const IOperand *> &stack) const = 0;
	virtual ~AInstruction() = default;

	std::pair<const IOperand*, const IOperand*>	getTwoElemFromStack(std::deque<const IOperand *> &stack) const;
};

class AddInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class AssertInstruction : public AInstruction
{
	const IOperand	*operand;

public:

	AssertInstruction();
	AssertInstruction(eOperandType type, std::string const &value);

	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class DivInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class DumpInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class ExitInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class ModInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class MulInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class PopInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class PrintInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class PushInstruction : public AInstruction
{
	const IOperand	*operand;

	PushInstruction();
	PushInstruction(PushInstruction const &);
	PushInstruction &operator=(PushInstruction const &);

public:

	PushInstruction(eOperandType type, std::string const &value);
	~PushInstruction() final;

	void doInstruction(std::deque<const IOperand*> &stack) const final;
};

class SubInstruction : public AInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const final;
};





#endif //ABSTRACTVM_AINSTRUCTION_HPP
