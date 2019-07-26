//
// Created by Vladyslav USLYSTYI on 2019-07-26.
//

#include <cstdint>
#include <cfloat>
#include "AVM.hpp"
#include "ExceptionAVM.hpp"

void	checkOverAndUnderFlow(long double v, eOperandType t)
{
	int		checkFlow = 0; // -1 under, 1 over

	if (t == Int8)
	{
		checkFlow = v > INT8_MAX ? 1 : checkFlow;
		checkFlow = v < INT8_MIN ? -1 : checkFlow;
	}
	else if (t == Int16)
	{
		checkFlow = v > INT16_MAX ? 1 : checkFlow;
		checkFlow = v < INT16_MIN ? -1 : checkFlow;
	}
	else if (t == Int32)
	{
		checkFlow = v > INT32_MAX ? 1 : checkFlow;
		checkFlow = v < INT32_MIN ? -1 : checkFlow;
	}
	else if (t == Float)
	{
		checkFlow = v > FLT_MAX ? 1 : checkFlow;
		checkFlow = v < -FLT_MAX ? -1 : checkFlow;
	}
	else if (t == Double)
	{
		checkFlow = v > DBL_MAX ? 1 : checkFlow;
		checkFlow = v < -DBL_MAX ? -1 : checkFlow;
	}

	if (checkFlow > 0)
		throw ExceptionAVM::ValueOverflow();
	if (checkFlow < 0)
		throw ExceptionAVM::ValueUnderflow();
}