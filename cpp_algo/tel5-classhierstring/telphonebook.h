// telphonebook.h
//
#ifndef _TELPHONEBOOK_H_
#define _TELPHONEBOOK_H_

#include <iostream>
#include "person.h"
#include "array.h"

const int MAXPERSONNUM = 100;

class TelPhoneBook
{
    CArray phoneList;

public:
    TelPhoneBook() {}
    ~TelPhoneBook() {}
    void insert();
    void remove();
    void search();
    void printAll();
};

#endif