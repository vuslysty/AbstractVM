//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_DIVINSTRUCTION_HPP
#define ABSTRACTVM_DIVINSTRUCTION_HPP

#include "Instruction.hpp"

class DivInstruction : Instruction
{
public:
	DivInstruction(int line);
	void doInstruction(std::deque<IOperand> &stack);
};


#endif //ABSTRACTVM_DIVINSTRUCTION_HPP
