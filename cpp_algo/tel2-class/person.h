// person.h
//
#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string.h>

const int MAXNAMELEN = 20;
const int MAXPHONELEN = 20;

class Person
{
protected:
    char name[MAXNAMELEN];
    char phone[MAXPHONELEN];

public:
    Person() {}
    Person(char *name, char *phone)
    {
        strcpy(this->name, name);
        strcpy(this->phone, phone);
    }
    const char *getName() const { return name; }
    const char *getPhone() const { return phone; }
    void print() const { std::cout << "Name : " << name << " | Phone : " << phone << std::endl; }
};
#endif
