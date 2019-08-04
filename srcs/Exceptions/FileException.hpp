//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#ifndef ABSTRACTVM_FILEEXCEPTION_HPP
#define ABSTRACTVM_FILEEXCEPTION_HPP

#include "ExceptionAVM.hpp"

class FileException : public ExceptionAVM
{};

class FileIsDirectoryException : public FileException
{
public:
	explicit FileIsDirectoryException(std::string const &file);
};

class FileCanNotOpenException : public FileException
{
public:
	explicit FileCanNotOpenException(std::string const &file);
};

class FileIsNotRegularException : public FileException
{
public:
	explicit FileIsNotRegularException(std::string const &file);
};

#endif //ABSTRACTVM_FILEEXCEPTION_HPP
