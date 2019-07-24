//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP


#include <string>
#include "../IOperand.hpp"

class OperandFactory
{
public:

	virtual const IOperand	*createOperand(std::string) const = 0;
	virtual const IOperand	*createOperand(void*) const = 0;
	virtual ~OperandFactory() {};
};


#endif //ABSTRACTVM_OPERANDFACTORY_HPP
