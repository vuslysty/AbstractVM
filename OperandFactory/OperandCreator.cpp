//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "OperandCreator.hpp"
#include "OperandFactory.hpp"

OperandCreator::OperandCreator()
{
	factories[0] = new Int8Factory();
	factories[1] = new Int16Factory();
	factories[2] = new Int32Factory();
	factories[3] = new FloatFactory();
	factories[4] = new DoubleFactory();
}

OperandCreator::OperandCreator(OperandCreator const &) {}
OperandCreator& OperandCreator::operator=(OperandCreator const &) {return *this;}
OperandCreator::~OperandCreator() {}

void OperandCreator::cleanInstance()
{
	if (instance)
	{
		for(auto & factorie : factories)
		{
			delete factorie;
			factorie = nullptr;
		}

		delete instance;
		instance = nullptr;
	}
}

OperandCreator* OperandCreator::getInstance()
{
	if (instance)
		return instance;
	else
	{
		instance = new OperandCreator();
		return (instance);
	}
}

IOperand const* OperandCreator::createOperand(eOperandType type,
											  std::string const &value)
{
	return factories[type]->createOperand(value);
}

OperandCreator		*OperandCreator::instance = nullptr;


OperandFactory const *OperandCreator::factories[5] = {
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr
};