//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_OPERANDCREATOR_HPP
#define ABSTRACTVM_OPERANDCREATOR_HPP


#include "../IOperand.hpp"
#include "OperandFactory.hpp"

class OperandCreator
{
	static OperandCreator		*instance;
	static OperandFactory const *factories[5];

	OperandCreator();
	OperandCreator(OperandCreator const &src);
	OperandCreator	&operator=(OperandCreator const &rhs);
public:

	~OperandCreator();

	static void				cleanInstance();
	static OperandCreator	*getInstance();
	IOperand const *createOperand(eOperandType type, std::string const &value);
};


#endif //ABSTRACTVM_OPERANDCREATOR_HPP
