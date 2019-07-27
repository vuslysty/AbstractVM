//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Convertor.hpp"
#include "OperandFactory/OperandFactory.hpp"

Convertor::~Convertor()
{
	if (delMode)
		delete rightOperand;
	else
		delete leftOperand;
}

Convertor::Convertor(IOperand const &lhs, IOperand const &rhs)
{
	if (lhs.getPrecision() > rhs.getPrecision())
	{
		leftOperand = &lhs;
		rightOperand = OperandFactory::create(lhs.getType(), rhs.toString());
		delMode = true;
	} else {
		leftOperand = OperandFactory::create(rhs.getType(), lhs.toString());
		rightOperand = &rhs;
		delMode = false;
	}
}

const IOperand& Convertor::getLeft()
{
	return *leftOperand;
}

const IOperand& Convertor::getRight()
{
	return *rightOperand;
}