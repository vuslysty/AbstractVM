//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_PRINTINSTRUCTION_HPP
#define ABSTRACTVM_PRINTINSTRUCTION_HPP


#include "IInstruction.hpp"

class PrintInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};

#endif //ABSTRACTVM_PRINTINSTRUCTION_HPP
