//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_MULINSTRUCTION_HPP
#define ABSTRACTVM_MULINSTRUCTION_HPP


#include "IInstruction.hpp"

class MulInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_MULINSTRUCTION_HPP
