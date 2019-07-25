//
// Created by Vladyslav USLYSTYI on 2019-07-15.
//

#include <iostream>
#include <string>
#include <regex>
#include <iterator>

#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim) {
	std::stringstream			ss(s);
	std::string					item;
	std::vector<std::string>	elems;

	while (std::getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

int main ()
{
//	std::string s (
//			"  		\n\n\n\npush 	int8     (23      )         	 \n"
//   			"add	; sadfjsaldfj\n  \n  		 	 "
//   			"pop;sdafasdf asdf asd fasdf\n"
//   			"print 	 \n    \n    \n\n\n	 	; asdfasdf	\n\n\n\n\n "
//	);
//
//	// delete comments
//	s = std::regex_replace (s, std::regex(";[^\n]*") ,"");
//
//	// delete white spaces befor and after OPEN_SCOPE | CLOSE_SCOPE
//	s = std::regex_replace (s ,std::regex("[\t ]*\\([\t ]*") ,"(");
//	s = std::regex_replace (s, std::regex("[\t ]*\\)[\t ]*"), ")");
//
//	// delete white spaces befor ENDLINE
//	s = std::regex_replace (s, std::regex("(\n[\t ]*)"), "\n");
//	// delete white spaces after ENDLINE
//	s = std::regex_replace (s, std::regex("([\t ]*\n)"), "\n");
//
//	// delete empty rows
//	s = std::regex_replace (s, std::regex("\n{2,}"), "\n");
//
//	// delete white spaces from begin of file
//	s = std::regex_replace (s, std::regex("([\t\n ]*)$)"), "", std::regex_constants::format_first_only);
//
//	// delete white spaces from end of file
//	s = std::regex_replace (s, std::regex("^([\t\n ]*))"), "", std::regex_constants::format_first_only);
//
//	// delete multiple white spaces
//	s = std::regex_replace (s, std::regex("[\t ]{2,}"), " ");
//
//	std::vector<std::string> lines = split(s, '\n');
//
//	for(unsigned int i = 0; i < lines.size(); i++)
//		std::cout << lines[i] << '\n';

//	int tmp = std::stoi("        -999999999");

	int a = -1;
	int b = INT32_MAX;
	int res = a * b;


	std::cout << 0.1 / -10;

	return 0;
}