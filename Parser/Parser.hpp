//
// Created by Vladyslav USLYSTYI on 2019-07-29.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

#include <string>
#include <deque>
#include "../Lexer/Token.hpp"
#include "../AVM.hpp"
#include <iterator>

class Parser
{
	std::deque<Token *>::iterator	iter;
	std::deque<Token *>::iterator	startInstr;
};


#endif //ABSTRACTVM_PARSER_HPP
