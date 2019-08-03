//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include "Executor.hpp"
#include "../Exceptions/ExceptionAVM.hpp"

static bool	fileIsDirectory(std::string const & fileName)
{
	bool		is_directory;
	FILE		*fp = fopen(fileName.c_str(), "rw");
	struct stat	fileInfo;

	fstat(fileno(fp), &fileInfo);
	if (S_ISREG(fileInfo.st_mode))
		is_directory = false;
	else
		is_directory = true;
	fclose(fp);
	return (is_directory);
}

Executor::Executor() : lexAnalysDone(false), parsAnalysDone(false),
	isFile(true)
{}

Executor::Executor(std::string const &src, bool isFile) : Executor()
{
	numSource++;

	if (!isFile)
	{
		this->fileName = "stdin";
		this->str = src;
		this->isFile = false;
		std::cout << BLUE_COLOR << "Source: " << STD_COLOR << fileName << std::endl;
	}
	else
	{
		std::ifstream		f(src, std::ifstream::in);
		std::stringstream	stream;

		fileName = src;
		std::cout << BLUE_COLOR << "Source: " << STD_COLOR << fileName << std::endl;
		if (f.is_open())
			if (!fileIsDirectory(src))
			{
				stream << f.rdbuf();
				str = stream.str();
			}
			else
			{
				f.close();
				throw FileException("\033[01;38;05;196mError:\033[m File is directory");
			}
		else
		{
			f.close();
			throw FileException("\033[01;38;05;196mError:\033[m Can't open file");
		}
		f.close();
	}
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
			//I must to add writing errors to file;
			std::cout << e.what() << std::endl;
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
			//I must to add writing errors to file;
			std::cout << e.what() << std::endl;
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

	try
	{
		while (!instructions.empty())
		{
			elem = instructions.front();
			elem->doInstruction(stack);
			instructions.pop();
			delete elem;
		}
		std::cout << GREEN_COLOR << "✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔ ✔" << STD_COLOR << std::endl;
	}
	catch (ExceptionAVM &e)
	{
		try
		{
			throw RunTimeExceptions(e.what(), elem);
		}
		catch (RunTimeExceptions &e)
		{
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