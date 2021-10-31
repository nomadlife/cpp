// person.h
//
#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include "str.h"

class Person
{
protected:
    String name;
    String phone;

public:
    Person() {}
    Person(const String &name, const String &phone)
    {
        this->name.assign(name);
        this->phone.assign(phone);
    }
    virtual ~Person() {}
    const String &getName() const { return name; }
    const String &getPhone() const { return phone; }
    virtual void print() const = 0;
};

class Friend : public Person
{
    String addr;

public:
    Friend(const String &name, const String &phone, const String &addr)
        : Person(name, phone) { this->addr.assign(addr); }
    ~Friend() {}
    const String &getAddr() const { return addr; }
    void print() const
    {
        Person::print();
        std::cout << " | Addr : ";
        addr.print();
        std::cout << std::endl;
    }
};

class Companion : public Person
{
    String pos;

public:
    Companion(const String &name, const String &phone, const String &pos)
        : Person(name, phone) { this->pos.assign(pos); }
    ~Companion() {}
    const String &getPosition() const { return pos; }
    void print() const
    {
        Person::print();
        std::cout << " | Position : ";
        pos.print();
        std::cout << std::endl;
    }
};

#endif