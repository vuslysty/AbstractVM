//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_INT32FACTORY_HPP
#define ABSTRACTVM_INT32FACTORY_HPP

#include "OperandFactory.hpp"

class Int32Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
	const IOperand	*createOperand(const void*) const;
};

#endif //ABSTRACTVM_INT32FACTORY_HPP
