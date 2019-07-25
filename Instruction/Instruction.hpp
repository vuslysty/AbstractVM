//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_INSTRUCTION_HPP
#define ABSTRACTVM_INSTRUCTION_HPP


#include <deque>
#include "../IOperand.hpp"
#include "../Fsm additions/Fsm.hpp"

class Instruction
{
public:

	virtual ~Instruction();

	virtual	void doInstruction(std::deque<const IOperand*> &stack) const = 0;
//	static	Instruction *createInstruction(int line);
//	static	Instruction *createInstruction(eInstruction instruction, int line);
//	static	Instruction *createInstruction(eInstruction, eOperandType,
//			eNumberType, std::string, int line);

};


#endif //ABSTRACTVM_INSTRUCTION_HPP
