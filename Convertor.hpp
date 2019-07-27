//
// Created by Vladyslav USLYSTYI on 2019-07-24.
//

#ifndef ABSTRACTVM_CONVERTOR_HPP
#define ABSTRACTVM_CONVERTOR_HPP

//#include "OperandFactory/OperandCreator.hpp"
#include "IOperand.hpp"

class Convertor
{
	const IOperand	*leftOperand;
	const IOperand	*rightOperand;
	bool		delMode;

	Convertor() = default;
	Convertor(Convertor const &src) = default;
	Convertor &operator=(Convertor const &rhs) = default;

public:

	Convertor(IOperand const &lhs, IOperand const &rhs);
	~Convertor();

	const IOperand	&getLeft();
	const IOperand	&getRight();
};


#endif //ABSTRACTVM_CONVERTOR_HPP
