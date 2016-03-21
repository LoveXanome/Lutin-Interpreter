#ifndef STRING_HELPER_HPP
#define STRING_HELPER_HPP

#include <string>

class StringHelper
{
public:
	static std::string format(const std::string& fmt_str, ...);
	static bool isOnlyWhitespaces(const std::string& str);
	static std::string doubleToString(const double d);
};

#endif // STRING_HELPER_HPP
