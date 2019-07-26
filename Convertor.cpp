//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "Convertor.hpp"
#include "OperandFactory/OperandCreator.hpp"

Convertor::Convertor() {}
Convertor::Convertor(Convertor const &) {}
Convertor& Convertor::operator=(Convertor const &) {return *this;}
Convertor::~Convertor()
{
	if (delMode)
		delete rightOperand;
	else
		delete leftOperand;
}

Convertor::Convertor(IOperand const &lhs, IOperand const &rhs)
{
	OperandCreator	*creator = OperandCreator::getInstance();

	if (lhs.getPrecision() > rhs.getPrecision())
	{
		leftOperand = &lhs;
		rightOperand = creator->createOperand(lhs.getType(), rhs.toString());
		delMode = true;
	} else {
		leftOperand = creator->createOperand(rhs.getType(), lhs.toString());
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