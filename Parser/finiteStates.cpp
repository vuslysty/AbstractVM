//
// Created by Vladyslav USLYSTYI on 2019-07-30.
//

#include "Parser.hpp"
#include "../Instruction/InstructionFactory/InstructionFactory.hpp"

int Parser::getCondition() const
{
	for (int i = InstEmpt; i < End; i++)
		if ((*iter)->getToken() == i)
			return (i);
	return (End);
}


static inline bool	isInt(eOperandType opT)
{
	return (opT == Int8 || opT == Int16 || opT == Int32);
}

void	Parser::numberState()
{
	numberValue = (*iter)->getValue();

	if (isInt(opType) && (*iter)->getToken() == NumZ)
		errorImplicitConversionNtoZ();
	else if (!isInt(opType) && (*iter)->getToken() == NumN)
		errorImplicitConversionZtoN();
}

void Parser::saveOperandType()
{
	(*iter)->getValue();

	for (int i = Int8; i <= Double; i++)
		if ((*iter)->getValue() == sOperandTypes[i])
			opType = static_cast<eOperandType >(i);
}

void Parser::FSnormalInstValue()
{
	InstructionFactory::create(*this);
}

void Parser::FSoptimizatedInstValue()
{
	InstructionFactory::create(*this);
}

void Parser::FSInstEmpt()
{
	instructions.push(InstructionFactory::create(*this));

	if (isUnusedInstructions)///
	;
	///////fsadf/sad/f/asdf//asdf
}

void Parser::FSoptimizatedEndLine()
{
	InstructionFactory::create(*this);
	errorNotEndLine();
}



