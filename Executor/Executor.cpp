//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include "Executor.hpp"
#include "../Exceptions/ExceptionAVM.hpp"
#include <zconf.h>
#include <ftw.h>

Executor::Executor() : errorFile(nullptr), lexAnalysDone(false), parsAnalysDone(false),
	isFile(true)
{}

Executor::Executor(std::string const &src, bool isFile) : Executor()
{
	std::stringstream	stream;

	numSource++;
	stream << "Source " << numSource;
	errorFileName = stream.str();

	if (!isFile)
	{
		this->fileName = "standard input";
		this->str = src;
		this->isFile = false;
		std::cout << BLUE_COLOR << errorFileName << ": " << STD_COLOR << fileName << std::endl;
	}
	else
		readTextFromFile(src);

	errorFile = new std::ofstream;
	errorFile->open(ERROR_PATH + errorFileName, std::ofstream::trunc);
}

Executor::Executor(Executor const &) {}
Executor& Executor::operator=(Executor const &) {return *this;}
Executor::~Executor()
{
	while (!tokens.empty())
	{
		Token			*tok;

		tok = tokens.front();
		tokens.pop_front();
		delete tok;
	}

	while (!instructions.empty())
	{
		AInstruction	*inst;

		inst = instructions.front();
		instructions.pop();
		delete inst;
	}

	while (!stack.empty())
	{
		const IOperand		*operand;

		operand = stack.front();
		stack.pop_front();
		delete operand;
	}

	delete errorFile;
}

void Executor::setOptimizationFlag(bool flag)
{
	optimizationFlag = flag;
}

void Executor::setFullErrorOutputFlag(bool flag)
{
	fullErrorOutputFlag = flag;
}

void Executor::doLexicalAnalys(Lexer *lexer)
{
	while (lexer->isWork())
	{
		try
		{
			lexer->doLexAnalization();
		}
		catch(std::exception &e)
		{
			writeErrorToFile(e.what());
			if (fullErrorOutputFlag || lexer->getErrorCount() < MAX_ERROR_OUTPUT)
				writeErrorToConsole(e.what());
		}
	}

	if (lexer->getErrorCount() > 0)
		std::cout << "Detected " << RED_COLOR << lexer->getErrorCount() <<
		" errors" << STD_COLOR << std::endl;
	else
		lexAnalysDone = true;
}

void Executor::doSyntaxAnalys(Parser *parser)
{
	while (parser->isWork())
	{
		try
		{
			parser->doParsAnalization();
		}
		catch(std::exception &e)
		{
			writeErrorToFile(e.what());
			if (fullErrorOutputFlag || parser->getErrorCount() < MAX_ERROR_OUTPUT)
				writeErrorToConsole(e.what());
		}
	}

	if (parser->getWarningCount() > 0)
		std::cout << "Detected " << VIOLET_COLOR << parser->getWarningCount()
		<< " warning(s)" << STD_COLOR << std::endl;

	if (parser->getErrorCount() > 0)
		std::cout << "Detected " << RED_COLOR << parser->getErrorCount() <<
		" error(s)" << STD_COLOR << std::endl;
	else
		parsAnalysDone = true;
}

void Executor::doExecution()
{
	AInstruction	*elem;

	try {
		try {
			while (!instructions.empty())
			{
				elem = instructions.front();
				elem->doInstruction(stack);
				instructions.pop();
				delete elem;
			}
			std::cout << RED_COLOR << "Error: " << STD_COLOR << "Not detected 'exit' instruction" << std::endl;
			std::cout << RED_COLOR << "✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘" << STD_COLOR << std::endl;
		} catch (ExitException &e) {
			std::cout << GREEN_COLOR << "✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔"
					  << STD_COLOR << std::endl;
		}
	} catch (ExceptionAVM &e) {
		try {
			throw RunTimeExceptions(e.what(), elem);
		}
		catch (RunTimeExceptions &e) {
			std::cout << e.what() << std::endl;
			std::cout << RED_COLOR << "✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘ ✘" << STD_COLOR << std::endl;
		}
	}
}

void Executor::startExecution()
{
	Lexer	*lexer = nullptr;
	Parser	*parser = nullptr;

	lexer = new Lexer(str, tokens);
	doLexicalAnalys(lexer);

	if (lexAnalysDone)
	{
		parser = new Parser(&tokens, instructions);
		parser->setOptimizator(optimizationFlag);
		doSyntaxAnalys(parser);
	}
	if (parsAnalysDone)
	{
		std::cout << "---------- START ----------\n";
		std::cout << "˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅ ˅\n";

		doExecution();

		std::cout << "----------- END -----------\n";
	}

	delete lexer;
	delete parser;
}

bool Executor::optimizationFlag = false;
bool Executor::fullErrorOutputFlag = false;

int Executor::numSource = 0;