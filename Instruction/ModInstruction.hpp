//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_MODINSTRUCTION_HPP
#define ABSTRACTVM_MODINSTRUCTION_HPP


#include "Instruction.hpp"

class ModInstruction : Instruction
{
public:
	explicit ModInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};


#endif //ABSTRACTVM_MODINSTRUCTION_HPP
