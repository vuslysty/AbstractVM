//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_DIVINSTRUCTION_HPP
#define ABSTRACTVM_DIVINSTRUCTION_HPP

#include "IInstruction.hpp"

class DivInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_DIVINSTRUCTION_HPP
