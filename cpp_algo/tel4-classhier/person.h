// person.h
//
#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string.h>

const int MAXNAMELEN = 20;
const int MAXPHONELEN = 20;
const int MAXADDRLEN = 50;
const int MAXPOSLEN = 30;

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
    ~Person() {}
    const char *getName() const { return name; }
    const char *getPhone() const { return phone; }
    virtual void print() const = 0;
};


class Friend : public Person
{
    char addr[MAXADDRLEN];

public:
    Friend(char *name, char *phone, char *addr)
        : Person(name, phone) { strcpy(this->addr, addr); }
    ~Friend() {}
    const char *getAddr() const { return addr; }
    void print() const
    {
        Person::print();
        std::cout << " | Addr : " << addr << std::endl;
    }
};


class Companion : public Person
{
    char pos[MAXPOSLEN];

public:
    Companion(char *name, char *phone, char *pos)
        : Person(name, phone) { strcpy(this->pos, pos); }
    ~Companion() {}
    const char *getPosition() const { return pos; }
    void print() const
    {
        Person::print();
        std::cout << " | Position : " << pos << std::endl;
    }
};
#endif
