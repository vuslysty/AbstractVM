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

#define ERROR_PATH "errors/"
#define MAX_ERROR_OUTPUT 20

class Executor
{
private:

	std::ofstream					*errorFile;
	bool							lexAnalysDone;
	bool							parsAnalysDone;
	bool 							isFile;

	std::string						fileName;

	static bool 					optimizationFlag;
	static bool						fullErrorOutputFlag;

	static int						numSource;

	std::string						str;
	std::deque<const IOperand *>	stack;
	std::deque<Token *> 			tokens;
	std::queue<AInstruction* >		instructions;

	std::string						errorFileName;

	Executor();

	void	doLexicalAnalys(Lexer *lexer);
	void	doSyntaxAnalys(Parser *parser);
	void	doExecution();

	void	writeErrorToFile(std::string const &src);
	void	writeErrorToConsole(std::string src);
	void	readTextFromFile(std::string const &src);

public:

	Executor(std::string const &src, bool isFile);
	Executor(Executor const &src);
	Executor &operator=(Executor const &rhs);
	~Executor();

	static void	setOptimizationFlag(bool flag);
	static void	setFullErrorOutputFlag(bool flag);

	void 	startExecution();
};


#endif //ABSTRACTVM_EXECUTOR_HPP
