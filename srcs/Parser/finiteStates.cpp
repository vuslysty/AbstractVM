//
// Created by Vladyslav USLYSTYI on 2019-07-30.
//

#include "Parser.hpp"
#include "../Instruction/InstructionFactory/InstructionFactory.hpp"
#include "../Exceptions/LimitException.hpp"

int Parser::getCondition() const
{
	eToken tokenType = (*iter)->getToken();

	for (int i = 0; i < TOKEN_COUNT; i++)
		if (tokenType == i)
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
		errorImplicitConversionZtoN();
	else if (!isInt(opType) && (*iter)->getToken() == NumN)
		errorImplicitConversionNtoZ();
}

void Parser::saveOperandType()
{
	(*iter)->getValue();

	for (int i = Int8; i <= Double; i++)
		if ((*iter)->getValue() == sOperandTypes[i])
		{
			opType = static_cast<eOperandType >(i);
			return ;
		}
}

void Parser::FSaddInstruction()
{
	AInstruction	*instruction = nullptr;
	try
	{
		if (errorCounter == 0 ||
			(errorCounter != 0 && (*startInstr)->getToken() == InstValue))
		{
			instruction = InstructionFactory::create(*this);
			if (errorCounter == 0)
				instructions.push(instruction);
			else
				delete instruction;
		}
	}
	catch (ValueOverflow &e)
	{
		delete instruction;
		errorCounter++;
		throw ValueOverflow(numberValue, (*startInstr)->getRow(),
				(*startInstr)->getCol());
	}
	catch (ValueUnderflow &e)
	{
		delete instruction;
		errorCounter++;
		throw ValueUnderflow(numberValue, (*startInstr)->getRow(),
				(*startInstr)->getCol());
	}
}

void Parser::FSoptimizatedEndLine()
{
	if (optimizator)
		FSaddInstruction();

	errorNotEndLine();
}