//
// Created by Vladyslav USLYSTYI on 2019-08-04.
//

#include <sys/stat.h>
#include <fstream>
#include "Executor.hpp"
#include "../Exceptions/FileException.hpp"

static void	replace(std::string &str, std::string const &s1, std::string const &s2)
{
	std::size_t 	found = 0;

	found = str.find(s1, found);
	if (found != std::string::npos)
		str.replace(found, s1.length(), s2);
}

static bool	fileIsDirectory(std::string const & fileName)
{
	bool		is_directory;
	FILE		*fp = fopen(fileName.c_str(), "rw");
	struct stat	fileInfo;

	fstat(fileno(fp), &fileInfo);

	if (S_ISDIR(fileInfo.st_mode))
		is_directory = true;
	else
		is_directory = false;
	fclose(fp);
	return (is_directory);
}

static bool	fileIsRegular(std::string const & fileName)
{
	bool		is_regular;
	FILE		*fp = fopen(fileName.c_str(), "rw");
	struct stat	fileInfo;

	fstat(fileno(fp), &fileInfo);

	if (S_ISREG(fileInfo.st_mode))
		is_regular = true;
	else
		is_regular = false;
	fclose(fp);
	return (is_regular);
}

void Executor::readTextFromFile(std::string const &src)
{
	std::ifstream		f(src, std::ifstream::in);
	std::stringstream	stream;

	fileName = src;
	std::cout << BLUE_COLOR << errorFileName << ": " << STD_COLOR << fileName << std::endl;
	if (f.is_open())
		if (fileIsDirectory(src))
		{
			f.close();
			throw FileIsDirectoryException(src);
		}
		else if (!fileIsRegular(src))
		{
			f.close();
			throw FileIsNotRegularException(src);
		}
		else
		{
			stream << f.rdbuf();
			str = stream.str();
		}
	else
	{
		f.close();
		throw FileCanNotOpenException(src);
	}
	f.close();
}

void Executor::writeErrorToFile(std::string const &src)
{
	*errorFile << src << std::endl;
}

void Executor::writeErrorToConsole(std::string src)
{
	static std::string	colorWarning = "\033[01;38;05;176mwarning\033[m";
	static std::string	colorError = "\033[01;38;05;167merror\033[m";

	replace(src, "warning", colorWarning);
	replace(src, "error", colorError);

	replace(src, " [", " \033[01m[");
	replace(src, "] ", "]\033[m ");

	std::cout << src << std::endl;
}