#include "StringHelper.hpp"

#include <memory>
#include <cstdarg>
#include <cstring>
#include <algorithm>

StringHelper::StringHelper()
{
}

StringHelper::~StringHelper()
{
}

/* http://stackoverflow.com/a/8098080 */
std::string StringHelper::format(const std::string& fmt_str, ...)
{
    int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
    std::string str;
    std::unique_ptr<char[]> formatted;
    va_list ap;
    while(1)
    {
        formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
        strcpy(&formatted[0], fmt_str.c_str());
        va_start(ap, fmt_str);
        final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);
        if (final_n < 0 || final_n >= n)
            n += abs(final_n - n + 1);
        else
            break;
    }
    return std::string(formatted.get());
}

bool StringHelper::isOnlyWhitespaces(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), isspace);
}
