//
// Created by Vladyslav USLYSTYI on 2019-07-26.
//

#include "OperandFactory.hpp"
#include "../Operand.hpp"

const IOperand* Int8Factory::createOperand(std::string value) const
{
	return new Operand<int8_t >(value);
}

const IOperand* Int16Factory::createOperand(std::string value) const
{
	return new Operand<int16_t >(value);
}

const IOperand* Int32Factory::createOperand(std::string value) const
{
	return new Operand<int32_t >(value);
}

const IOperand* FloatFactory::createOperand(std::string value) const
{
	return new Operand<float >(value);
}

const IOperand* DoubleFactory::createOperand(std::string value) const
{
	return new Operand<double >(value);
}


const IOperand	*OperandFactory::create(eOperandType type, std::string const &value)
{
	return factories[type]->createOperand(value);
}

void OperandFactory::delFactory()
{
	for (int i = Int8; i <= Double; i++)
		delete factories[i];
}


OperandFactory	*OperandFactory::factories[5] =
		{
			new Int8Factory(),
			new Int16Factory(),
			new Int32Factory(),
			new FloatFactory(),
			new DoubleFactory()
		};
