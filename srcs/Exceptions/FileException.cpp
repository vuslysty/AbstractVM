//
// Created by Vladyslav USLYSTYI on 2019-08-02.
//

#include <sstream>
#include "FileException.hpp"

FileCanNotOpenException::FileCanNotOpenException(std::string const &file)
{
	std::stringstream	stream;

	stream << RED_COLOR << "Error: " << STD_COLOR <<
	"File '" << file << "' can not be open";
	message = stream.str();
}

FileIsDirectoryException::FileIsDirectoryException(std::string const &file)
{
	std::stringstream	stream;

	stream << RED_COLOR << "Error: " << STD_COLOR <<
		   "File '" << file << "' is directory";
	message = stream.str();
}

FileIsNotRegularException::FileIsNotRegularException(std::string const &file)
{
	std::stringstream	stream;

	stream << RED_COLOR << "Error: " << STD_COLOR <<
		   "File '" << file << "' is not regular";
	message = stream.str();
}