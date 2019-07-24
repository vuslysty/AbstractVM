//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_ASSERTINSTRUCTION_HPP
#define ABSTRACTVM_ASSERTINSTRUCTION_HPP


#include "Instruction.hpp"

class AssertInstruction : Instruction
{
public:
	AssertInstruction(int line);
	void doInstruction(std::deque<IOperand> &stack);
};


#endif //ABSTRACTVM_ASSERTINSTRUCTION_HPP
