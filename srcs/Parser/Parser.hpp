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

class Parser;

typedef void (Parser::*transitionP_callback)();

struct transitionP
{
	int 					newState;
	transitionP_callback	worker;
};

class Parser
{
	std::queue<AInstruction* >	&instructions;

	bool			fullErrorOutput;
	bool			optimizator;

	unsigned int	errorCounter;
	unsigned int	warningCounter;
	int 			currState;
	int				prevState;

	eOperandType	opType;
	std::string		numberValue;

	std::deque<Token *>::iterator	iter;
	std::deque<Token *>::iterator	startInstr;
	std::deque<Token *>::iterator	endIter;

	static const transitionP		fsmTable[8][10];

	void	numberState();
	void	saveOperandType();

	void	FSaddInstruction();
	void	FSoptimizatedEndLine();

	void	errorNotValue();
	void	errorNotOpenScope();
	void	errorNotNumber();
	void	errorEmptyScopes();
	void	errorImplicitConversionZtoN();
	void	errorImplicitConversionNtoZ();
	void	errorNotCloseScope();
	void	errorNotEndLine();
	void	errorUnknownInstruction();
	void	errorBadLogicPosition();

	int 	getCondition() const;


//	Parser() = delete;

public:

	explicit Parser(std::deque<Token *> *tokens, std::queue<AInstruction* > &inst);

	void			doParsAnalization();
	bool			isWork() const;

	unsigned int	getErrorCount() const;
	unsigned int	getWarningCount() const;

	eInstruction 	getInstructionType() const;
	eOperandType	getOperandType() const;
	std::string		getNumValue() const;
	Token 			*getStartToken() const;

	std::queue<AInstruction* >	&getInstructions();

	void 			setOptimizator(bool optimization);
};


#endif //ABSTRACTVM_PARSER_HPP
