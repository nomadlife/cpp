// str.cpp
//

#include "str.h"

String::String(char *s)
{
    if (s)
    {
        size = strlen(s);
        data = new char[size + 1];
        strcpy(data, s);
    }
    else
    {
        data = 0;
        size = 0;
    }
}

String::String(const String &s)
{
    size = s.size;
    data = new char[size + 1];
    strcpy(data, s.data);
}

String &String::assign(const String &s)
{
    if (this == &s)
        return *this;
    if (data)
        delete[] data;
    size = s.size;
    data = new char[size + 1];
    strcpy(data, s.data);
    return *this;
}

bool String::isEqual(const String &s) const
{
    return strcmp(data, s.data) == 0 ? true : false;
}
