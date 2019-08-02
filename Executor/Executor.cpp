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

Executor::Executor() : lexAnalysDone(false), parsAnalysDone(false)
{}

Executor::Executor(std::string const &src, bool isFile) : Executor()
{
	if (!isFile)
		this->str = src;
	else
	{
		std::ifstream		f(src, std::ifstream::in);
		std::stringstream	stream;

		if (f.is_open())
			if (!fileIsDirectory(src))
			{
				stream << f.rdbuf();
				str = stream.str();
			}
			else
				throw FileException("Error: File is directory");
		else
			throw FileException("Error: Can't open file");
	}
}

Executor::Executor(Executor const &) {}
Executor& Executor::operator=(Executor const &) {return *this;}
Executor::~Executor() {}

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
		std::cout << "Detected " << lexer->getErrorCount() << " errors" << std::endl;
	else
	{
		tokens = lexer->getTokens();
		lexAnalysDone = true;
	}
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
		std::cout << "Detected " << parser->getWarningCount() << " warning(s)" << std::endl;

	if (parser->getErrorCount() > 0)
		std::cout << "Detected " << parser->getErrorCount() << " error(s)" << std::endl;
	else
	{
		instructions = parser->getInstructions();
		parsAnalysDone = true;
	}
}

void Executor::startExecution()
{
	AInstruction	*elem;

	try
	{
		// add start execution
		while (!instructions.empty())
		{
			elem = instructions.front();
			elem->doInstruction(stack);
			instructions.pop();
		}
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
		}
	}

}

void Executor::doExecution()
{
	Lexer	*lexer = nullptr;
	Parser	*parser = nullptr;

	lexer = new Lexer(str);
	doLexicalAnalys(lexer);

	if (lexAnalysDone)
	{
		parser = new Parser(&tokens);
		doSyntaxAnalys(parser);
	}
	if (parsAnalysDone)
	{

	}
}