//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_DIVINSTRUCTION_HPP
#define ABSTRACTVM_DIVINSTRUCTION_HPP

#include "Instruction.hpp"

class DivInstruction : Instruction
{
public:
	explicit DivInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};


#endif //ABSTRACTVM_DIVINSTRUCTION_HPP
