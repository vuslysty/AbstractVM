//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_ADDINSTRUCTION_HPP
#define ABSTRACTVM_ADDINSTRUCTION_HPP


#include "Instruction.hpp"

class AddInstruction : Instruction
{
public:
	AddInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack);
};


#endif //ABSTRACTVM_ADDINSTRUCTION_HPP
