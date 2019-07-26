//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP


#include <string>
#include "../IOperand.hpp"

class OperandFactory
{
public:

	virtual const IOperand	*createOperand(std::string) const = 0;
	virtual ~OperandFactory() {};
};

class Int8Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
};

class Int16Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
};

class Int32Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
};

class FloatFactory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
};

class DoubleFactory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const;
};


#endif //ABSTRACTVM_OPERANDFACTORY_HPP
