//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_PUSHINSTRUCTION_HPP
#define ABSTRACTVM_PUSHINSTRUCTION_HPP

#include "IInstruction.hpp"

class PushInstruction : public IInstruction
{
	const IOperand	*operand;

public:

	PushInstruction();
	PushInstruction(eOperandType type, std::string const &value);

	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_PUSHINSTRUCTION_HPP
