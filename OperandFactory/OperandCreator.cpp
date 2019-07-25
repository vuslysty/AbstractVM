//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#include "OperandCreator.hpp"
#include "Int8Factory.hpp"
#include "Int32Factory.hpp"
#include "Int16Factory.hpp"
#include "FloatFactory.hpp"
#include "DoubleFactory.hpp"

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

IOperand const* OperandCreator::createOperand(eOperandType type,
											  void const *value)
{
	return factories[type]->createOperand(value);
}

OperandCreator		*OperandCreator::instance = nullptr;

//OperandFactory const *OperandCreator::factories[5] = {
//		[0] = new Int8Factory(),
//		[1] = new Int16Factory(),
//		[2] = new Int32Factory(),
//		[3] = new FloatFactory(),
//		[4] = new DoubleFactory()
//};

OperandFactory const *OperandCreator::factories[5] = {
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr
};