//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_INT16FACTORY_HPP
#define ABSTRACTVM_INT16FACTORY_HPP


#include "OperandFactory.hpp"

class Int16Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
	const IOperand	*createOperand(void*) const;
};


#endif //ABSTRACTVM_INT16FACTORY_HPP
