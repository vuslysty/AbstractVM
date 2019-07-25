//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_PRINTINSTRUCTION_HPP
#define ABSTRACTVM_PRINTINSTRUCTION_HPP


#include "Instruction.hpp"

class PrintInstruction : Instruction
{
public:
	explicit PrintInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};

#endif //ABSTRACTVM_PRINTINSTRUCTION_HPP
