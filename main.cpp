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

std::vector<std::string> split(const std::string &s, char delim) {
	std::stringstream			ss(s);
	std::string					item;
	std::vector<std::string>	elems;

	while (std::getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

#include "OperandFactory/OperandCreator.hpp"
#include <deque>

int main ()
{
	OperandCreator *creator = OperandCreator::getInstance();
	std::deque<const IOperand *>	stack;

	stack.push_front(creator->createOperand(Int32, "45"));
	stack.push_front(creator->createOperand(Float, "23.54"));

	for (auto item : stack)
	{
		std::cout << item->getType() << " " << item->toString(2) << std::endl;
	}

	return 0;
}