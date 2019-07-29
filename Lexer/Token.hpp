//
// Created by Vladyslav USLYSTYI on 2019-07-28.
//

#ifndef ABSTRACTVM_TOKEN_HPP
#define ABSTRACTVM_TOKEN_HPP

#include <string>
#include "../AVM.hpp"

class Token
{
	eToken				token;
	std::string			sValue;
	unsigned long 		row;
	unsigned long 		col;

	Token() = default;

public:

	Token(eToken t, std::string value, unsigned long row, unsigned long col);
	Token(Token const &src);
	Token &operator=(Token const &rhs);
	~Token() = default;

	eToken				getToken() const;
	std::string			getValue() const;
	std::string			getTokenByStr() const;
	unsigned long  		getRow() const;
	unsigned long  		getCol() const;
};


#endif //ABSTRACTVM_TOKEN_HPP
