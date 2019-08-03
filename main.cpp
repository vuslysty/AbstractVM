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

int main ()
{

	system("chmod 777 errors &> /dev/null");
	del_files();

	Executor	*exec = new Executor("millionMAP_", true);

	exec->setOptimizationFlag(true);

	exec->startExecution();

	delete exec;
	






	system("leaks -q AbstractVM");

	system("chmod 555 errors &> /dev/null");

	return 0;
}