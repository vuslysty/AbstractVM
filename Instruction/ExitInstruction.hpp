//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_EXITINSTRUCTION_HPP
#define ABSTRACTVM_EXITINSTRUCTION_HPP


#include "Instruction.hpp"

class ExitInstruction : Instruction
{
public:
	ExitInstruction(int line);
	void doInstruction(std::deque<IOperand> &stack);
};


#endif //ABSTRACTVM_EXITINSTRUCTION_HPP
