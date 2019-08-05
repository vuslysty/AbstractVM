//
// Created by Vladyslav USLYSTYI on 2019-07-15.
//

#include "Exceptions/ExceptionAVM.hpp"
#include "Executor/Executor.hpp"
#include "Exceptions/FileException.hpp"
#include <sys/stat.h>

static void del_files()
{
	std::stringstream	stream;
	int 				i;
	std::string			str = ERROR_PATH;

	chmod(ERROR_PATH, 0777);
	i = 1;
	str = str + "Source " + std::to_string(i++);

	while (remove(str.c_str()) >= 0)
	{
		str = ERROR_PATH;
		str.append("Source " + std::to_string(i++));
	}
	chmod(ERROR_PATH, 0555);
}

static std::string readFromSTDIN()
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

static int check_flags(int argc, char **argv)
{
	int 		i = 0;
	std::string arg;

	while (++i < argc)
	{
		arg = argv[i];
		if (arg[0] != '-' || (arg[0] == '-' && arg[1] == '\0'))
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

void	getHelp()
{
	std::cout << "usage: ./abstractVM [-o][-f] [file_1 ... file_N]" << std::endl;
	std::cout << "-o	- optimization flag" << std::endl;
	std::cout << "1. You can write more than one instruction per line" << std::endl;
	std::cout << "2. You can skip the brackets" << std::endl;
	std::cout << "3. You can skip the explicit conversion during addition value" << std::endl;
	std::cout << std::endl;
	std::cout << "-f	- full error output" << std::endl << std::endl;
	std::cout << "*Abstract VM GRAMMAR*" << std::endl;

	std::cout << "S := INSTR [SEP INSTR]* #" << std::endl << std::endl;

	std::cout << "INSTR :=" << std::endl;
	std::cout << "	  push VALUE" << std::endl;
	std::cout << "	| pop" << std::endl;
	std::cout << "	| dump" << std::endl;
	std::cout << "	| assert VALUE" << std::endl;
	std::cout << "	| add" << std::endl;
	std::cout << "	| sub" << std::endl;
	std::cout << "	| mul" << std::endl;
	std::cout << "	| div" << std::endl;
	std::cout << "	| mod" << std::endl;
	std::cout << "	| exit" << std::endl;
	std::cout << "BONUS INSTRUCTION:" << std::endl;
	std::cout << "	| min" << std::endl;
	std::cout << "	| max" << std::endl;
	std::cout << "	| front" << std::endl;
	std::cout << "	| back" << std::endl << std::endl;

	std::cout << "VALUE :=" << std::endl;
	std::cout << "	  int8(N)" << std::endl;
	std::cout << "	| int16(N)" << std::endl;
	std::cout << "	| int32(N)" << std::endl;
	std::cout << "	| float(Z)" << std::endl;
	std::cout << "	| double(Z)" << std::endl << std::endl;

	std::cout << "N := [-]?[0..9]+" << std::endl << std::endl;

	std::cout << "Z := [-]?[0..9]+.[0..9]+" << std::endl << std::endl;

	std::cout << "SEP := '\\n'+" << std::endl << std::endl;

	std::cout << "SIMPLE COMMENT := ';'" << std::endl << std::endl;

	std::cout << "BONUS:" << std::endl;
	std::cout << "MULTI-LINE COMMENT :=  /; *some text* ;/" << std::endl;
}

int		main (int argc, char **argv)
{
	Executor	*exec;
	int 		i;

	if (argc == 2 && strcmp(argv[1], "--help") == 0)
	{
		getHelp();
		return (0);
	}
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
					exec->startExecution();
					delete exec;
				} catch (FileException &e) {
					std::cout << e.what() << std::endl;
				}
				std::cout << std::endl;
				i++;
			}

	} catch (ExceptionAVM &e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "strange exception" << std::endl;
	}

	return 0;
}