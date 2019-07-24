//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_DOUBLEFACTORY_HPP
#define ABSTRACTVM_DOUBLEFACTORY_HPP


#include "OperandFactory.hpp"

class DoubleFactory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
	const IOperand	*createOperand(void*) const;
};


#endif //ABSTRACTVM_DOUBLEFACTORY_HPP
