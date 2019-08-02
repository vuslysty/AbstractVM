//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#include "ExceptionAVM.hpp"

FileException::FileException(std::string const &fileName)
{
	message = fileName;
}