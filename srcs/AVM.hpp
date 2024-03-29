//
// Created by Vladyslav USLYSTYI on 2019-07-25.
//

#ifndef ABSTRACTVM_AVM_HPP
#define ABSTRACTVM_AVM_HPP


#include <string>

#define INSTR_COUNT 	15
#define OPER_TYPE_COUNT 5
#define TOKEN_COUNT 	10

#define STD_COLOR "\033[m"
#define RED_COLOR "\033[01;38;05;167m"
#define GREEN_COLOR "\033[01;38;05;190m"
#define VIOLET_COLOR "\033[01;38;05;176m"
#define BLUE_COLOR "\033[01;38;05;110m"

enum	eInstruction{
	Push, Assert, Pop, Dump, Add, Sub, Mul, Div, Mod, Print, Min, Max, Front, Back, Exit
};

const std::string sInstrutions[INSTR_COUNT] = {
		"push", "assert", "pop", "dump", "add", "sub", "mul", "div", "mod",
		"print", "min", "max", "front", "back", "exit"
};

enum	eOperandType{
	Int8, Int16, Int32, Float, Double
};

const std::string sOperandTypes[OPER_TYPE_COUNT] = {
		"int8", "int16", "int32", "float", "double"
};

enum eToken{ InstEmpt, InstValue, InstBad, OperandType, OpenScope, CloseScope, NumN, NumZ, EndLine, End };

void		checkOverAndUnderFlow(long double v, eOperandType t);
std::string	getStrValueWithPrecision(long double value, eOperandType type,
										int precision);
void		longDoubleOverUnderFlow(std::string const &value);

void	checkInt8Limits(long double value);
void	checkInt16Limits(long double value);
void	checkInt32Limits(long double value);
void	checkFloatLimits(long double value);
void	checkDoubleLimits(long double value);

#endif //ABSTRACTVM_AVM_HPP
