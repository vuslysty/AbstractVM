//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_FLOATFACTORY_HPP
#define ABSTRACTVM_FLOATFACTORY_HPP


#include "OperandFactory.hpp"
#include "../Operand.hpp"

class FloatFactory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
	const IOperand	*createOperand(const void*) const;
};


#endif //ABSTRACTVM_FLOATFACTORY_HPP
