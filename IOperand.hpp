//
// Created by Vladyslav USLYSTYI on 2019-07-15.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP


//#include "Fsm additions/Fsm.hpp"


#include "AVM.hpp"
#include <string>

class IOperand
{
public:

	virtual int 				getPrecision(void) const = 0;
	virtual eOperandType		getType() const = 0;
	virtual	const std::string	&toString(int n = 20) const = 0;
	virtual	IOperand const		*operator+(IOperand const &rhs) const = 0;
	virtual	IOperand const		*operator-(IOperand const &rhs) const = 0;
	virtual	IOperand const		*operator*(IOperand const &rhs) const = 0;
	virtual	IOperand const		*operator/(IOperand const &rhs) const = 0;
	virtual	IOperand const		*operator%(IOperand const &rhs) const = 0;
	virtual bool                operator==(IOperand const &rhs) const = 0;
	virtual bool                operator!=(IOperand const &rhs) const = 0;

	virtual ~IOperand() {};
};

#endif //ABSTRACTVM_IOPERAND_HPP
