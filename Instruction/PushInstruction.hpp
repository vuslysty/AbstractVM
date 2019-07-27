//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_PUSHINSTRUCTION_HPP
#define ABSTRACTVM_PUSHINSTRUCTION_HPP

#include "IInstruction.hpp"
#include "../AVM.hpp"

class PushInstruction : public IInstruction
{
	const IOperand	*operand;

public:

	PushInstruction();
	PushInstruction(eOperandType type, std::string const &value);

	PushInstruction(PushInstruction const &);
	PushInstruction &operator=(PushInstruction const &);
	~PushInstruction() final;

	void doInstruction(std::deque<const IOperand*> &stack) const final;
};


#endif //ABSTRACTVM_PUSHINSTRUCTION_HPP
