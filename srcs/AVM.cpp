//
// Created by Vladyslav USLYSTYI on 2019-07-26.
//

#include <cstdint>
#include <cfloat>
#include "AVM.hpp"
#include <sstream>
#include <iomanip>
#include "Exceptions/LimitException.hpp"

void	checkOverAndUnderFlow(long double v, eOperandType t)
{
	static void (*limits[5])(long double) = {
		checkInt8Limits,
		checkInt16Limits,
		checkInt32Limits,
		checkFloatLimits,
		checkDoubleLimits
	};

	limits[t](v);
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