//
// Created by Vladyslav USLYSTYI on 2019-07-15.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP

enum	eOperandType{};

class IOperand
{
public:

	virtual int 			getPrecision(void) const = 0;
	virtual eOperandType
};

#endif //ABSTRACTVM_IOPERAND_HPP
