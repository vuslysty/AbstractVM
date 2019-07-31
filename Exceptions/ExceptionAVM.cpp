//
// Created by Vladyslav USLYSTYI on 2019-07-31.
//

#include "ExceptionAVM.hpp"

const char* ExceptionAVM::what() const _NOEXCEPT
{
	return (message.c_str());
}