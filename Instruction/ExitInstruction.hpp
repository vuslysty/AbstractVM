//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_EXITINSTRUCTION_HPP
#define ABSTRACTVM_EXITINSTRUCTION_HPP


#include "Instruction.hpp"

class ExitInstruction : Instruction
{
public:
	explicit ExitInstruction(int line);
	void doInstruction(std::deque<const IOperand*> &stack) final;
};


#endif //ABSTRACTVM_EXITINSTRUCTION_HPP
