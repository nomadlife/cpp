// array.h
//
#ifndef _CARRAY_H_
#define _CARRAY_H_
#include <iostream>
#include "person.h"
typedef Person ArrayElm;
const int EXPANSIONRATE = 2;
class CArray
{
    ArrayElm *arr;
    int aidx;
    int size;

public:
    CArray(int sz = 10) : aidx(0), size(sz) { arr = new ArrayElm[size]; }
    ~CArray() { delete[] arr; }
    void insert(ArrayElm obj);
    void update(ArrayElm obj, int idx);
    void remove(int idx);
    ArrayElm &getItem(int idx);
    const int getSize() const { return aidx; }
};
#endif