//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#ifndef ABSTRACTVM_EXECUTOR_HPP
#define ABSTRACTVM_EXECUTOR_HPP

#include <iostream>
#include <string>
#include <regex>
#include <iterator>

#include <string>
#include <sstream>
#include <vector>


#include "../Instruction/AInstruction.hpp"
#include "../Instruction/InstructionFactory/InstructionFactory.hpp"
#include "../Lexer/Lexer.hpp"
#include "../Exceptions/ExceptionAVM.hpp"
#include "../Exceptions/RunTimeExceptions.hpp"
#include <deque>
#include <map>
#include <iomanip>

#define MAX_ERROR_OUTPUT 20

class Executor
{
private:

	bool							lexAnalysDone;
	bool							parsAnalysDone;

	static bool 					optimizationFlag;
	static bool						fullErrorOutputFlag;

	std::string						str;
	std::deque<const IOperand *>	stack;
	std::deque<Token *> 			tokens;

	std::queue<AInstruction* >		instructions;

	Executor();

	void	doLexicalAnalys(Lexer *lexer);
	void	doSyntaxAnalys(Parser *parser);
	void 	startExecution();

public:

	Executor(std::string const &src, bool isFile);
	Executor(Executor const &src);
	Executor &operator=(Executor const &rhs);
	~Executor();

	void	setOptimizationFlag(bool flag);
	void	setFullErrorOutputFlag(bool flag);

	void	doExecution();
};


#endif //ABSTRACTVM_EXECUTOR_HPP