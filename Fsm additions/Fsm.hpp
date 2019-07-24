//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_FSM_HPP
#define ABSTRACTVM_FSM_HPP

#include <iostream>
#include <iterator>
#include <string>
#include <queue>

#define INSTR_COUNT 	11
#define OPER_TYPE_COUNT 5

enum	eInstruction{
	Push, Assert, Pop, Dump, Add, Sub, Mul, Div, Mod, Print, Exit
};

enum	eOperandType{
	Int8, Int16, Int32, Float, Double
};

enum	eNumberType{
	N, Z
};

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

	std::queue<*IInstruction>	instructionQueue;

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

	Fsm();
	Fsm(std::string const &fileName);

	void	doFsm();

};

#endif //ABSTRACTVM_FSM_HPP
