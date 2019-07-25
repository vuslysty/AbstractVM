//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_ASSERTINSTRUCTION_HPP
#define ABSTRACTVM_ASSERTINSTRUCTION_HPP


#include "IInstruction.hpp"

class AssertInstruction : public IInstruction
{
	IOperand	*operand;

public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_ASSERTINSTRUCTION_HPP
