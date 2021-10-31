// str.h
//
#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include <string.h>

class String
{
    char *data;
    int size;

public:
    String(char *s = 0);
    String(const String &);
    ~String()
    {
        if (data)
            delete[] data;
    }
    const int length() const { return size; }
    const char *getData() const { return data; }
    String &assign(const String &);
    bool isEqual(const String &) const;
    void print() const { std::cout << data; }
};
#endif