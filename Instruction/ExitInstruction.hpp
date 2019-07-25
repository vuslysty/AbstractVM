//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_EXITINSTRUCTION_HPP
#define ABSTRACTVM_EXITINSTRUCTION_HPP


#include "IInstruction.hpp"

class ExitInstruction : public IInstruction
{
public:
	void doInstruction(std::deque<const IOperand*> &stack) const;
};


#endif //ABSTRACTVM_EXITINSTRUCTION_HPP
