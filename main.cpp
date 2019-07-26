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
#include "Instruction/IInstruction.hpp"
#include "Instruction/InstructionFactory/InstructionFactory.hpp"
#include "Instruction/PushInstruction.hpp"
#include "Instruction/PrintInstruction.hpp"
#include "Instruction/AddInstruction.hpp"
#include "Instruction/MulInstruction.hpp"
#include "Instruction/DivInstruction.hpp"
#include "Instruction/ModInstruction.hpp"
#include "Instruction/DumpInstruction.hpp"
#include <deque>
#include <map>

void	test(std::deque<const IOperand *> &stack)
{
	OperandCreator *creator = OperandCreator::getInstance();

	const IOperand	*e1 = creator->createOperand(Int32, "45");
	const IOperand	*e2 = creator->createOperand(Float, "23.54");

	stack.push_front(e1);
	stack.push_front(e2);
}

int main ()
{
	std::deque<const IOperand *>	stack;
//
	std::multimap<int, IInstruction* >	mapInstuctions;

//	mapInstuctions.insert({1, new PushInstruction(Int16, "53")});
//	mapInstuctions.insert({2, new PushInstruction(Int16, "99")});
//	mapInstuctions.insert({3, new PushInstruction(Int16, "24")});
//	mapInstuctions.insert({4, new PushInstruction(Int16, "34")});
//	mapInstuctions.insert({5, new PushInstruction(Int16, "62.52")});
//	mapInstuctions.insert({6, new PushInstruction(Int16, "72")});

	mapInstuctions.insert({1, new PushInstruction(Int8, "100")});
	mapInstuctions.insert({2, new PushInstruction(Int16, "-32767")});
	mapInstuctions.insert({3, new PushInstruction(Int32, "24")});
	mapInstuctions.insert({4, new PushInstruction(Float, "34")});
	mapInstuctions.insert({5, new PushInstruction(Double, "6272384579228.52")});
	mapInstuctions.insert({6, new PushInstruction(Int8, "76")});
	mapInstuctions.insert({7, new PrintInstruction()});
	mapInstuctions.insert({8, new DumpInstruction()});

//
	for(auto item : mapInstuctions)
	{
		item.second->doInstruction(stack);
	}

//	test(stack);
//
//	for (auto item : stack)
//	{
//		static int i = 0;
//		std::cout << ++i << ": " << item->getType() << " " << item->toString(2) << std::endl;
//	}

	return 0;
}