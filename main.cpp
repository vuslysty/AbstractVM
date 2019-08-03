//
// Created by Vladyslav USLYSTYI on 2019-07-15.
//

#include <iostream>
#include <string>
#include <regex>
#include <iterator>

#include <string>
#include <sstream>
#include <vector>


#include "Instruction/AInstruction.hpp"
#include "Instruction/InstructionFactory/InstructionFactory.hpp"
#include "Lexer/Lexer.hpp"
#include "Exceptions/ExceptionAVM.hpp"
#include "Exceptions/RunTimeExceptions.hpp"
#include "Executor/Executor.hpp"
#include <deque>
#include <map>
#include <iomanip>


int main ()
{
//	std::deque<const IOperand *>	stack;
//
//	const IOperand *pointer = stack.front();
//
//
//	delete pointer;
//
//	Lexer	lexer("millionMAP_2", true);
//
//	while (lexer.isWork())
//	{
//		try
//		{
//			lexer.doLexAnalization();
//		}
//		catch(std::exception &e)
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
//	std::cout << "Expected " << lexer.getErrorCount() << " errors" << std::endl;
//
//
//	std::deque<Token *> 		tokens = lexer.getTokens();
//
//
//	Parser	parser(&tokens);
//
//	parser.setOptimizator(true);
//
//	while (parser.isWork())
//	{
//		try
//		{
//			parser.doParsAnalization();
//		}
//		catch(std::exception &e)
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
//
//	std::queue<AInstruction* >	instructions = parser.getInstructions();
//
//	AInstruction * elem;
//
//	try
//	{
//		while (!instructions.empty())
//		{
//			elem = instructions.front();
//			elem->doInstruction(stack);
//			instructions.pop();
//		}
//	}
//	catch (ExceptionAVM &e)
//	{
//		try
//		{
//			throw RunTimeExceptions(e.what(), elem);
//		}
//		catch (RunTimeExceptions &e)
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
//
//	const IOperand *pointer = stack.front();
//	delete pointer;

	Executor	*exec = new Executor("millionMAP_", true);

	exec->setOptimizationFlag(true);

	exec->startExecution();

	delete exec;

	system("leaks -q AbstractVM");

	return 0;
}