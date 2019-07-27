//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_AVM_HPP
#define ABSTRACTVM_AVM_HPP


#include <string>

#define INSTR_COUNT 	11
#define OPER_TYPE_COUNT 5

enum	eInstruction{
	Push, Assert, Pop, Dump, Add, Sub, Mul, Div, Mod, Print, Exit
};

enum	eOperandType{
	Int8, Int16, Int32, Float, Double
};

enum	eNumberType{
	N, Z
};

void		checkOverAndUnderFlow(long double v, eOperandType t);
std::string	getStrValueWithPrecision(long double value, eOperandType type,
										bool mod);

#endif //ABSTRACTVM_AVM_HPP
