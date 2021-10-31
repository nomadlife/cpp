#ifndef _MergeSort_h
#define _MergeSort_h

#include <assert.h>
namespace cppalgo {
template <class TYPE>
void MergeSort(TYPE a[], int n)
{
	int i, j, k, first, second, size;
	TYPE *b;
	// ������ �޸𸮰��� �Ҵ� 
	b = new TYPE [n];
	assert(b != 0);

	for (size = 1; size < n; size *= 2)
	{
		first = 0;
		second = size;
		while (second < n)
		{
			i = first;
			j = second;
			k = first;
			while (i < first + size || (j < second + size && j < n))
			{
				if (a[i] > a[j])
				{
					if (j < second + size && j < n)
						b[k++] = a[j++];
					else
						b[k++] = a[i++];
				} 
				else 
				{
					if (i < first + size)
						b[k++] = a[i++];
					else
						b[k++] = a[j++];
				}
			}
			first += 2*size;
			second += 2*size;
		}
		for (i = 0; i < n; i++)
			a[i] = b[i];    // ���� 
	}
	delete [] b;
}

template <class TYPE>
void MergeSort_ex(TYPE a[], int n)
{
	int i, j, k, first, second, size;
	TYPE *b;
	// ������ �޸𸮰��� �Ҵ� 
	b = new TYPE [n];
	assert(b != 0);

	TYPE *src = a;
	TYPE *tmp = b;

	for (size = 1; size < n; size *= 2)
	{
		first = 0;
		second = size;
		while (second < n)
		{
			i = first;
			j = second;
			k = first;
			while (i < first + size || (j < second + size && j < n))
			{
				if (src[i] > src[j])
				{
					if (j < second + size && j < n)
						tmp[k++] = src[j++];
					else
						tmp[k++] = src[i++];
				} 
				else 
				{
					if (i < first + size)
						tmp[k++] = src[i++];
					else
						tmp[k++] = src[j++];
				}
			}
			first += 2*size;
			second += 2*size;
		}
		TYPE *t = src;		// �ι迭 �����͸� ��ȯ 
		src = tmp;
		tmp = t;
	}
	// ������ �ʿ䰡 �ִ°�?
	if (tmp == a) 
	{
		for (int i = 0; i < n; i++) a[i] = b[i];
	}
	delete [] b;
}

};
#endif