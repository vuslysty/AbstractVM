//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_ADDINSTRUCTION_HPP
#define ABSTRACTVM_ADDINSTRUCTION_HPP


#include "IInstruction.hpp"

class AddInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_ADDINSTRUCTION_HPP
