//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_DUMPINSTRUCTION_HPP
#define ABSTRACTVM_DUMPINSTRUCTION_HPP

#include "Instruction.hpp"

class DumpInstruction : Instruction
{
public:
	DumpInstruction(int line);
	void doInstruction(std::deque<IOperand> &stack);
};

#endif //ABSTRACTVM_DUMPINSTRUCTION_HPP
