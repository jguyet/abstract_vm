#include <string>
#include <cctype>

bool is_numeric(const std::string& s)
{
    std::string::const_iterator it = s.begin();
	while (it != s.end() && *it == '-') ++it;
    while (it != s.end() && (std::isdigit(*it) || *it == '.')) ++it;
    return !s.empty() && it == s.end();
}
