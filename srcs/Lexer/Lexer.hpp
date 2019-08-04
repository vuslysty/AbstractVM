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

#define MAX_ERROR_OUTPUT 20

class Lexer;

typedef bool	(Lexer::*Conditions)(const char c) const;

typedef void (Lexer::*transitionL_callback)();

struct transitionL
{
	int 					newState;
	transitionL_callback	worker;
};

class Lexer
{
	std::deque<Token *>	&tokens;
	int 				state;

	unsigned int		errorCount;
	bool				stop;
	unsigned int 		row;
	unsigned int 		col;
	unsigned int 		carret;
	unsigned int 		startToken;
	unsigned int		startColumn;

	unsigned int		startRow;
	unsigned int 		startTokenTMP;
	unsigned int		startColumnTMP;
	std::string			str;

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
	void	moveCarretBack();
	void	countEndLines();
	void	workBeforeException(unsigned int move_step);

	void	errorMinus();
	void	errorDot();
	void	errorIdent();
	void	errorMultilineComment();

	static Conditions conditions[CONDITION_COUNT];

	int 	getCondition() const;

	static const transitionL		fsmTable[10][12];

public:

	explicit Lexer(std::string const &src, std::deque<Token *> &toks);
	Lexer(Lexer const &src);
	Lexer &operator=(Lexer const &rhs);
	~Lexer();

	void	doLexAnalization();
	bool	isWork() const;
	unsigned int	getErrorCount() const;

	std::deque<Token *> &getTokens();
};

#endif //ABSTRACTVM_LEXER_HPP
