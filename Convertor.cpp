//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Convertor.hpp"
#include "OperandFactory/OperandCreator.hpp"

Convertor::Convertor(IOperand const &lhs, IOperand const &rhs)
{
	OperandCreator	*creator = OperandCreator::getInstance();

	if (lhs.getPrecision() > rhs.getPrecision())
	{
		leftOperand = &rhs;
		rightOperand = creator->createOperand(lhs.getType(), rhs.getValue());
		delMode = true;
	} else {
		leftOperand = creator->createOperand(rhs.getType(), lhs.getValue());
		rightOperand = &rhs;
		delMode = false;
	}
}