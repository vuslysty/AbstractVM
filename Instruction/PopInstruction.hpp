//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_POPINSTRUCTION_HPP
#define ABSTRACTVM_POPINSTRUCTION_HPP


#include "Instruction.hpp"

class PopInstruction : Instruction
{
public:
	explicit PopInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};


#endif //ABSTRACTVM_POPINSTRUCTION_HPP
