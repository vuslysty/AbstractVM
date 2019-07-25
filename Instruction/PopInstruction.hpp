//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_POPINSTRUCTION_HPP
#define ABSTRACTVM_POPINSTRUCTION_HPP


#include "IInstruction.hpp"

class PopInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_POPINSTRUCTION_HPP
