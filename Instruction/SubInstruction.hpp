//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_SUBINSTRUCTION_HPP
#define ABSTRACTVM_SUBINSTRUCTION_HPP


#include "IInstruction.hpp"

class SubInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_SUBINSTRUCTION_HPP
