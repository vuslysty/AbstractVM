//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

#include <string>
#include <deque>
#include <queue>
#include "../Lexer/Token.hpp"
#include "../AVM.hpp"
#include "../Instruction/AInstruction.hpp"
#include <iterator>

#define MAX_ERROR_OUTPUT 20

class Parser;

typedef void (Parser::*transitionP_callback)();

struct transitionP
{
	int 					newState;
	transitionP_callback	worker;
};

class Parser
{
	eOperandType	opType;

	bool			fullErrorOutput;
	bool			isUnusedInstructions;
	bool			optimizator;

	unsigned int	errorCounter;
	unsigned int	warningCounter;
	int 			state;

	std::string		numberValue;

	void	numberState();
	void	saveOperandType();
//	void	saveNumber(); // in optimized and normal number

	void	FSnormalInstValue();
	void	FSoptimizatedInstValue();
	void	FSInstEmpt();
	void	FSoptimizatedEndLine();
//	void	FSstop(); // work while not defined END

	//!!! first change state, then call matching function !!!

	void	errorNotValue();
	void	errorNotOpenScope(); // if Up optimization flag and token N or Z - throw warning and go to 7 state
	void	errorNotNumber();
	void	errorEmptyScopes();
	void	errorImplicitConversionZtoN();
	void	errorImplicitConversionNtoZ();
	void	errorNotCloseScope();
	void	errorNotEndLine(); // add optimization
	void	errorUnknownInstruction();
	void	errorBadLogicPosition();
	void	warningUnusedInstructions();


	std::deque<Token *>::iterator	iter;
	std::deque<Token *>::iterator	startInstr;
	std::deque<Token *>::iterator	endIter;

	std::queue<AInstruction* >		instructions;

	int 	getCondition() const;

	static const transitionP		fsmTable[8][10];

public:

	void			doParsAnalization();
	bool			isWork() const;
	unsigned int	getErrorCount() const;
	unsigned int	getWarningCount() const;

	eInstruction 	getInstructionType() const;
	eOperandType	getOperandType() const;
	std::string		getNumValue() const;


	void 			setFullErrorOutputState(bool FullErrorOutputMode);
};


#endif //ABSTRACTVM_PARSER_HPP
