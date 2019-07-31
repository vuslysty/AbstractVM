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
	bool			fullErrorOutput;
	bool			optimizator;

	unsigned int	errorCounter;
	unsigned int	warningCounter;
	int 			currState;
	int				prevState;

	eOperandType	opType;
	std::string		numberValue;

	void	numberState();
	void	saveOperandType();
//	void	saveNumber(); // in optimized and normal number

	void	FSaddInstruction();
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


	std::deque<Token *>::iterator	iter;
	std::deque<Token *>::iterator	startInstr;
	std::deque<Token *>::iterator	endIter;

	std::queue<AInstruction* >		instructions;

	int 	getCondition() const;

	static const transitionP		fsmTable[8][10];

	Parser();

public:

	Parser(std::deque<Token *> *tokens);

	void			doParsAnalization();
	bool			isWork() const;
	unsigned int	getErrorCount() const;
	unsigned int	getWarningCount() const;

	eInstruction 	getInstructionType() const;
	eOperandType	getOperandType() const;
	std::string		getNumValue() const;
	Token 			*getStartToken() const;

	std::queue<AInstruction* >	getInstructions() const;


	void 			setFullErrorOutputState(bool fullErrorOutputMode);
	void 			setOptimizator(bool optimization);
};


#endif //ABSTRACTVM_PARSER_HPP
