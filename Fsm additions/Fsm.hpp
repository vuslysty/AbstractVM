//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_FSM_HPP
#define ABSTRACTVM_FSM_HPP

#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include "../AVM.hpp"
//#include "../Instruction/IInstruction.hpp"

enum	eSyntax{
	Zero = '\0', EndLine = '\n', Comment = ';'
};

struct	s_fsmFlags {

	bool						stop;
	bool						error;

	bool						instruction;
	bool						operandType;
	bool						number; // up when number was reading
};

class Fsm
{
	s_fsmFlags					flags;

	unsigned int				rowNum;

	eInstruction				instruction;
	eOperandType				operandType;
	eNumberType					numberType;

	unsigned int				beginInstruction;
	unsigned int				beginNum;
	unsigned int				endNum;
	unsigned int				carret;

	int							currState;
	int 						tmpVar;
	std::string					str;

//	std::map<int, *IInstruction>	instructionMap;

	static const std::string sOperandTypes[OPER_TYPE_COUNT];
	static const std::string sInstrutions[INSTR_COUNT];

	// FSM conditions
	bool	zeroCond(char *c);
	bool	endLineCond(char *c);
	bool	commentCond(char *c);
	bool	numberCond(char *c);
	bool	whiteSpaceCondition(char *c);
	bool	minusCond(char *c);
	bool	dotCond(char *c);
	bool	openScopeCond(char *c);
	bool	closeScopeCond(char *c);

	bool	instructionCond(char *c);
	bool	operandTypeCond(char *c);

	// FSM states
	void	checkInstruction();
	void	checkOperandType();
	void	beginOfNumber();
	void	endOfNumberN();
	void	endOfNumberZ();
	void	changeInstruction();
	void	error();

public:

	Fsm(std::string const &fileName);
	void	doFsm();

	eInstruction	getInstructionType() const;
	eOperandType	getOperandType() const;
	eNumberType		getNumberType() const;
	std::string		getNumberInString() const;

	Fsm();

};

#endif //ABSTRACTVM_FSM_HPP
