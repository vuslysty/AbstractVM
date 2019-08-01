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

#include "Instruction/AInstruction.hpp"
#include "Instruction/InstructionFactory/InstructionFactory.hpp"
#include "Lexer/Lexer.hpp"
#include "Exceptions/ExceptionAVM.hpp"
#include <deque>
#include <map>
#include <iomanip>


int main ()
{
	std::deque<const IOperand *>	stack;
//
//	std::multimap<int, AInstruction* >	mapInstuctions;

//	mapInstuctions.insert({1, new PushInstruction(Double, "99.9943875982374")});
//	mapInstuctions.insert({2, new PushInstruction(Int16, "99")});
//	mapInstuctions.insert({3, new PushInstruction(Int16, "24")});
//	mapInstuctions.insert({4, new PushInstruction(Int16, "34")});
//	mapInstuctions.insert({5, new PushInstruction(Int16, "62.52")});
//	mapInstuctions.insert({6, new PushInstruction(Int16, "72")});

//	mapInstuctions.insert({1, new PushInstruction(Float, "33245312432412342342345243613242346786")});
//	mapInstuctions.insert({2, new PushInstruction(Int16, "-32767")});
//	mapInstuctions.insert({3, new PushInstruction(Int32, "24")});
//	mapInstuctions.insert({4, new PushInstruction(Float, "34")});
//	mapInstuctions.insert({5, new PushInstruction(Double, "6272384579228.52")});
//	mapInstuctions.insert({6, new PushInstruction(Int8, "28")});
//	mapInstuctions.insert({7, new PrintInstruction()});
//	mapInstuctions.insert({8, new DumpInstruction()});
//	mapInstuctions.insert({9, new MulInstruction()});
//	mapInstuctions.insert({10, new SubInstruction()});
//	mapInstuctions.insert({11, new AddInstruction()});
//	mapInstuctions.insert({12, new DivInstruction()});
//	mapInstuctions.insert({13, new DivInstruction()});
//	mapInstuctions.insert({13, new ModInstruction()});

//	mapInstuctions.insert({15, new DumpInstruction()});
//	mapInstuctions.insert({16, new AssertInstruction(Float, "33245312432412342342345243613242346786")});

//	std::cout <<  << std::endl;

//	for(auto item : mapInstuctions)
//	{
//		item.second->doInstruction(stack);
//	}

//	test(stack);
//
//	for (auto item : stack)
//	{
//		static int i = 0;
//		std::cout << ++i << ": " << item->getType() << " " << item->toString(2) << std::endl;
//	}

//	Lexer	lexer("-4   /;   3  \n\n\n 234234233523;/   2.4	4	;3.3",
//				   false);

//--------------------------------------

	Lexer	lexer("millionMAP_", true);

	while (lexer.isWork())
	{
		try
		{
			lexer.doLexAnalization();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "Expected " << lexer.getErrorCount() << " errors" << std::endl;


	std::deque<Token *> 		&tokens = lexer.getTokens();


	Parser	parser(&tokens);

	parser.setOptimizator(true);

	while (parser.isWork())
	{
		try
		{
			parser.doParsAnalization();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::queue<AInstruction* >	&instructions = parser.getInstructions();

	AInstruction * elem;

	try
	{
		while (!instructions.empty())
		{
			elem = instructions.front();
			elem->doInstruction(stack);
			instructions.pop();
		}
	}
	catch (ExceptionAVM &e)
	{
		std::cout << e.what() << std::endl <<
		instructions.front()->getRow() << ":" << instructions.front()->getColumn();
	}



//	tokens.emplace(++tokens.begin(), new Token(EndLine, "LooooL", 42, 23));

//	for (auto item : tokens)
//		std::cout << std::setw(15) << item->getTokenByStr() << ": " << item->getValue() << std::endl;


	return 0;
}