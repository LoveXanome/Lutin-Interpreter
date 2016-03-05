#ifndef STRING_HELPER_HPP
#define STRING_HELPER_HPP

#include <string>

class StringHelper
{
public:
	virtual ~StringHelper();
	
	static std::string format(const std::string& fmt_str, ...);
	
private:
	StringHelper();
};


#endif // STRING_HELPER_HPP
