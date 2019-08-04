//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#include <cstdint>
#include <cfloat>
#include "AVM.hpp"
#include <sstream>
#include <iomanip>
#include "Exceptions/LimitException.hpp"

void	checkInt8Limits(long double value)
{
	value > INT8_MAX ? throw ValueOverflow() : 0;
	value < INT8_MIN ? throw ValueUnderflow() : 0;
}

void	checkInt16Limits(long double value)
{
	value > INT16_MAX ? throw ValueOverflow() : 0;
	value < INT16_MIN ? throw ValueUnderflow() : 0;
}

void	checkInt32Limits(long double value)
{
	value > INT32_MAX ? throw ValueOverflow() : 0;
	value < INT32_MIN ? throw ValueUnderflow() : 0;
}

void	checkFloatLimits(long double value)
{
	if (value > FLT_MAX || value < -FLT_MAX)
		throw ValueOverflow();
	else if ((value > 0 && value < FLT_MIN) || (value < 0 && value > -FLT_MIN))
		throw ValueUnderflow();
}

void	checkDoubleLimits(long double value)
{
	if (value > DBL_MAX || value < -DBL_MAX)
		throw ValueOverflow();
	else if ((value > 0 && value < DBL_MIN) || (value < 0 && value > -DBL_MIN))
		throw ValueUnderflow();
}