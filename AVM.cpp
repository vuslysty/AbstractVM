//
// Created by Vladyslav USLYSTYI on 2019-07-26.
//

#include <cstdint>
#include <cfloat>
#include "AVM.hpp"
#include "ExceptionAVM.hpp"
#include <sstream>
#include <iomanip>
#include "Exceptions/LimitException.hpp"

void	checkOverAndUnderFlow(long double v, eOperandType t)
{
	if (t == Int8)
	{
		v > INT8_MAX ? throw ValueOverflow() : 0;
		v < INT8_MIN ? throw ValueUnderflow() : 0;
	}
	else if (t == Int16)
	{
		v > INT16_MAX ? throw ValueOverflow() : 0;
		v < INT16_MIN ? throw ValueUnderflow() : 0;
	}
	else if (t == Int32)
	{
		v > INT32_MAX ? throw ValueOverflow() : 0;
		v < INT32_MIN ? throw ValueUnderflow() : 0;
	}
	else if (t == Float)
	{
		if (v > FLT_MAX || v < -FLT_MAX)
			throw ValueOverflow();
		else if ((v > 0 && v < FLT_MIN) || (v < 0 && v > -FLT_MIN))
			throw ValueUnderflow();
	}
	else if (t == Double)
	{
		if (v > DBL_MAX || v < -DBL_MAX)
			throw ValueOverflow();
		else if ((v > 0 && v < DBL_MIN) || (v < 0 && v > -DBL_MIN))
			throw ValueUnderflow();
	}
}

void	longDoubleOverUnderFlow(std::string const &value)
{
	auto	i = value.begin();

	if (*i == '-')
		i++;

	while (*i == '0')
		i++;

	if (*i == '.')
		throw ValueUnderflow();
	else
		throw ValueOverflow();
}

std::string	getStrValueWithPrecision(long double value, eOperandType type,
										int precision)
{
	std::ostringstream	out;

	if (type >= Int8 && type <= Int32)
		out << std::fixed << std::setprecision(0) << value;
	else if (type == Float)
		out << std::fixed << std::showpoint << std::setprecision(precision) << value;
	else
		out << std::fixed << std::showpoint << std::setprecision(precision) << value;

	return (out.str());
}