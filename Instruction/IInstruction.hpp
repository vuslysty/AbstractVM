//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_IINSTRUCTION_HPP
#define ABSTRACTVM_IINSTRUCTION_HPP


#include <deque>
//#include "../Fsm additions/Fsm.hpp"

class IOperand;

class IInstruction
{
public:
	
	virtual	void doInstruction(std::deque<const IOperand *> &stack) const = 0;
	virtual ~IInstruction() = default;
};




#endif //ABSTRACTVM_IINSTRUCTION_HPP
