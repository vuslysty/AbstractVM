//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_ASSERTINSTRUCTION_HPP
#define ABSTRACTVM_ASSERTINSTRUCTION_HPP


#include "Instruction.hpp"

class AssertInstruction : Instruction
{
public:
	explicit AssertInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};


#endif //ABSTRACTVM_ASSERTINSTRUCTION_HPP
