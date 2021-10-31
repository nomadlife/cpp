// telphonebook.h
//
#ifndef _TELPHONEBOOK_H_
#define _TELPHONEBOOK_H_

#include <iostream>
#include "person.h"

const int MAXPERSONNUM = 100;

class TelPhoneBook
{
    Person phoneList[MAXPERSONNUM];
    int pidx;

public:
    TelPhoneBook() : pidx(0) {}
    ~TelPhoneBook() {}
    void insert();
    void remove();
    void search();
    void printAll();
};
#endif