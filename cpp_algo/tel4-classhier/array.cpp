// array.cpp
//
#include "array.h"

void CArray::insert(ArrayElm obj)
{
    if (size <= aidx)
    {
        // memory expansion
        ArrayElm *tarr = new ArrayElm[size * EXPANSIONRATE];
        for (int i = 0; i < size; i++)
            tarr[i] = arr[i];
        delete[] arr;
        arr = tarr;
        size = size * 2;
    }
    arr[aidx++] = obj;
}

void CArray::update(ArrayElm obj, int idx)
{
    if (idx < 0 || idx >= aidx)
        return;
    arr[idx] = obj;
}

void CArray::remove(int idx)
{
    if (idx < 0 || idx >= aidx)
        return;
    for (int i = idx; i < aidx - 1; i++)
        arr[i] = arr[i + 1];
    aidx--;
}

ArrayElm &CArray::getItem(int idx)
{
    if (idx < 0 || idx >= aidx)
        return *(new ArrayElm());
    return arr[idx];
}