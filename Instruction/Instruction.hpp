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
protected:
	int	line;

	Instruction();
	Instruction(int line);
	Instruction(Instruction const &src);
	Instruction &operator=(Instruction const &rhs);

public:

	virtual ~Instruction();

	virtual	void doInstruction(std::deque<IOperand> &stack);
	static	Instruction *createInstruction(int line);
	static	Instruction *createInstruction(eInstruction instruction, int line);
	static	Instruction *createInstruction(eInstruction, eOperandType,
			eNumberType, std::string, int line);


};


#endif //ABSTRACTVM_INSTRUCTION_HPP
