//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#ifndef ABSTRACTVM_LEXER_HPP
#define ABSTRACTVM_LEXER_HPP


#include <string>
#include <deque>
#include "Token.hpp"
#include "../AVM.hpp"

#define CONDITION_COUNT 11

class Lexer;

typedef bool	(Lexer::*Conditions)(const char c) const;

typedef void (Lexer::*transition_callback)();

struct transition
{
	int 				newState;
	transition_callback worker;
};

class Lexer
{
	unsigned long 		row;
	unsigned long 		col;
	bool				stop;
	unsigned int 		carret;
	unsigned int 		startToken;

	std::string			str;
	std::deque<Token *>	tokens;

	Lexer();

	bool	whiteCondition(const char c) const;
	bool	alphaCondition(const char c) const;
	bool	numCondition(const char c) const;
	bool	openScopeCondition(const char c) const;
	bool	closeScopeCondition(const char c) const;
	bool	minusCondition(const char c) const;
	bool	dotCondition(const char c) const;
	bool	endLineCondition(const char c) const;
	bool	commentCondition(const char c) const;
	bool	zeroCondition(const char c) const;
	bool	slashCondition(const char c) const;

	void	identifierFS();
	void	openScopeFS();
	void	closeScopeFS();
	void	numNFS();
	void	numZFS();
	void	endLineFS();
	void	endFS();

	void	moveStartToken();
	void	countEndLines();

	void	errorMinus();
	void	errorDot();
	void	errorIdent();
	void	errorMultilineComment();

	static Conditions conditions[CONDITION_COUNT];

	int 	getCondition() const;

	void	startLexAnalization();

	static const transition		fsmTable[10][12];

public:

	explicit Lexer(std::string const &str, bool file);
	Lexer(Lexer const &src);
	Lexer &operator=(Lexer const &rhs);
	~Lexer();

	std::deque<Token *>	getTokens() const;
};

#endif //ABSTRACTVM_LEXER_HPP
