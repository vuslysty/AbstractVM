//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_INT8FACTORY_HPP
#define ABSTRACTVM_INT8FACTORY_HPP


#include "OperandFactory.hpp"

class Int8Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const final;
	const IOperand	*createOperand(const void*) const final;
};


#endif //ABSTRACTVM_INT8FACTORY_HPP
