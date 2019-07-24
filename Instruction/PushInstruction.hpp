//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_PUSHINSTRUCTION_HPP
#define ABSTRACTVM_PUSHINSTRUCTION_HPP

#include "Instruction.hpp"

class PushInstruction : Instruction
{
public:
	explicit PushInstruction(int line);
	void doInstruction(std::deque<IOperand> &stack);
};


#endif //ABSTRACTVM_PUSHINSTRUCTION_HPP
