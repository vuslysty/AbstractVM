//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_MODINSTRUCTION_HPP
#define ABSTRACTVM_MODINSTRUCTION_HPP


#include "IInstruction.hpp"

class ModInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_MODINSTRUCTION_HPP
