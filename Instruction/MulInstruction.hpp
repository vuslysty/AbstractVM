//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_MULINSTRUCTION_HPP
#define ABSTRACTVM_MULINSTRUCTION_HPP


#include "Instruction.hpp"

class MulInstruction : Instruction
{
public:
	MulInstruction(int line);
	void doInstruction(std::deque<IOperand> &stack);
};


#endif //ABSTRACTVM_MULINSTRUCTION_HPP
