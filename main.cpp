//
// Created by Vladyslav USLYSTYI on 2019-07-15.
//

#include <iostream>
#include <string>
#include <regex>
#include <iterator>

int main ()
{
	std::string s (
			"  		\n\n\n\npush 	int8     (23      )         	 \n"
   			"add	; sadfjsaldfj\n  \n  		 	 "
   			"pop;sdafasdf asdf asd fasdf\n"
   			"print 	 \n    \n    \n\n\n	 	; asdfasdf	 "
	);

	s = std::regex_replace (s, std::regex(";[^\n]*") ,"");

	s = std::regex_replace (s ,std::regex("[\t ]*\\([\t ]*") ,"(");

	s = std::regex_replace (s, std::regex("[\t ]*\\)[\t ]*"), ")");

	s = std::regex_replace (s, std::regex("(\n[\t ]*)"), "\n");

	s = std::regex_replace (s, std::regex("([\t ]*\n)"), "\n");

	// delete empty rows
	s = std::regex_replace (s, std::regex("\n{2,}"), "\n");

	// delete white spaces from begin of file
	s = std::regex_replace (s, std::regex("([\t\n ]*)$)"), "", std::regex_constants::format_first_only);

	// delete white spaces from end of file
	s = std::regex_replace (s, std::regex("^([\t\n ]*))"), "", std::regex_constants::format_first_only);

	// delete multiple white spaces
	s = std::regex_replace (s, std::regex("[\t ]{2,}"), " ");

	std::cout << s;


	return 0;
}