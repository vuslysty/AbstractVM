//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_DUMPINSTRUCTION_HPP
#define ABSTRACTVM_DUMPINSTRUCTION_HPP

#include "IInstruction.hpp"

class DumpInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};

#endif //ABSTRACTVM_DUMPINSTRUCTION_HPP
