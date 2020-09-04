#include "valid.h"

bool num_valid(std::string str)
{
	char tmp[1028];
	if (_itoa_s(atoi(str.c_str()), tmp, 10) == 0) // Converting string to num and then back to string
		if (str == tmp) // If the strings are equal and no errors occur
			return true;

	return false;
}

bool str_valid(std::string str)
{
	if (!str.empty() && str.find_first_not_of(' ') >= 0) // If the string is not empty and consist not only of spaces
		return true;

	return false;
}