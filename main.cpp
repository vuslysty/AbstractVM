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
#include "Exceptions/FileException.hpp"
#include <deque>
#include <map>
#include <iomanip>

void del_files()
{
	std::stringstream	stream;
	int 				i;
	std::string			str = ERROR_PATH;

	i = 1;
	str = str + "Source " + std::to_string(i++);

	while (remove(str.c_str()) >= 0)
	{
		str = ERROR_PATH;
		str = str + "Source " + std::to_string(i++);
	}
}

std::string readFromSTDIN()
{
	std::stringstream	stream;
	std::string line;

	while (line != ";;")
	{
		if (std::cin.eof())
			break ;
		std::getline(std::cin, line, '\n');
		stream << line << '\n';
	}
	return stream.str();
}

int check_flags(int argc, char **argv)
{
	int 		i = 0;
	std::string arg;

	while (++i < argc)
	{
		arg = argv[i];
		if (arg[0] != '-')
			break ;
		for (auto c = ++arg.begin(); c != arg.end(); ++c)
		{
			if (*c == 'o')
				Executor::setOptimizationFlag(true);
			else if (*c == 'f')
				Executor::setFullErrorOutputFlag(true);
			else
				throw InvalidFlagException(*c);
		}
	}
	return (i);
}

int main (int argc, char **argv)
{
	Executor	*exec;
	int 		i;

	try
	{
		del_files();
		i = check_flags(argc, argv);

		if (i == argc)
		{
			exec = new Executor(readFromSTDIN(), false);
			exec->startExecution();
			delete exec;
		}
		else
			while (i < argc)
			{
				try
				{
					exec = new Executor(argv[i], true);
					exec->startExecution();delete exec;
				} catch (FileException &e) {
					std::cout << e.what() << std::endl;
				}
				std::cout << std::endl;
				i++;
			}

	} catch (ExceptionAVM &e){
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "strange exception" << std::endl;
	}

	system("leaks -q AbstractVM");

	return 0;
}