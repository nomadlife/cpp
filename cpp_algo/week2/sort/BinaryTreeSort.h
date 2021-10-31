#ifndef _BinaryTreeSort_h
#define _BinaryTreeSort_h

#include "../Search/BinTreeMap.h"

namespace cppalgo
{
template <class TYPE>
void BinaryTreeSort(TYPE a[], int n)
{
	BinTreeMap<TYPE> bintree;
	
	// ���� ����Ÿ�� �����Ѵ�. 
	for (int i = 0; i < n; i++)
		bintree.Insert(a[i]);

	// ���� 
	bintree.Sort(a, n);
}
};

#endif