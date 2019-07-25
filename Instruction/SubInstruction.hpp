//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_SUBINSTRUCTION_HPP
#define ABSTRACTVM_SUBINSTRUCTION_HPP


#include "Instruction.hpp"

class SubInstruction : Instruction
{
public:
	explicit SubInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};


#endif //ABSTRACTVM_SUBINSTRUCTION_HPP
