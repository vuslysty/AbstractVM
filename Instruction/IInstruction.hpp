//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_IINSTRUCTION_HPP
#define ABSTRACTVM_IINSTRUCTION_HPP


#include <deque>
#include "../IOperand.hpp"
#include "../Fsm additions/Fsm.hpp"

class IInstruction
{
public:

	virtual ~IInstruction();

	virtual	void doInstruction(std::deque<const IOperand *> &stack) const = 0;
//	static	IInstruction *createInstruction(int line);
//	static	IInstruction *createInstruction(eInstruction instruction, int line);
//	static	IInstruction *createInstruction(eInstruction, eOperandType,
//			eNumberType, std::string, int line);

};


#endif //ABSTRACTVM_IINSTRUCTION_HPP
