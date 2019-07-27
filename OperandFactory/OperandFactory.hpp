//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP


#include <string>
#include "../IOperand.hpp"

class OperandFactory
{
	static OperandFactory	*factories[5];

	virtual const IOperand	*createOperand(std::string) const = 0;

public:

	static const IOperand	*create(eOperandType type,
							   std::string const &value);

	static void				delFactory();

	virtual ~OperandFactory() = default;
};

class Int8Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const final;
};

class Int16Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const final;
};

class Int32Factory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const final;
};

class FloatFactory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const final;
};

class DoubleFactory : public OperandFactory
{
public:

	const IOperand	*createOperand(std::string) const final;
};


#endif //ABSTRACTVM_OPERANDFACTORY_HPP
