#include "StringUtil.h"

#include <string>

namespace gameplay
{

inline char lowercase(char c)
{
    if (c >= 'A' && c <='Z')
    {
        c |= 0x20;
    }
    return c;
}

bool endsWith(const char* str, const char* suffix, bool ignoreCase)
{
    size_t length = strlen(str);
    size_t suffixLength = strlen(suffix);

    if (suffixLength > length)
    {
        return false;
    }

    size_t offset = length - suffixLength;

    const char* p = str + offset;
    while (*p != '\0')
    {
        if (ignoreCase)
        {
            if (lowercase(*p) != lowercase(*suffix))
            {
                return false;
            }
        }
        else if (*p != *suffix)
        {
            return false;
        }
        
        ++p;
        ++suffix;
    }
    return true;
}

bool equals(const std::string& a, const char* b)
{
    return (a.compare(b) == 0);
}

bool equalsIgnoreCase(const std::string& a, const char* b)
{
    size_t bLength = strlen(b);
    if (a.size() != bLength)
    {
        return false;
    }
    for (size_t i = 0; i < bLength; i++)
    {
        if (lowercase(a[i]) != lowercase(b[i]))
        {
            return false;
        }
    }
    return true;
}

}