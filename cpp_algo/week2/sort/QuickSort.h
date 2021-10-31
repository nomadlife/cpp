#ifndef _QuickSort_h
#define _QuickSort_h

#include <assert.h>
#include "../Stack/ListStack.h"
#include "../Stack/ArrayStack.h"
#include "InsertionSort.h"

namespace cppalgo {
template <class TYPE>
void QuickSort(TYPE a[], int n)
{
	TYPE v, t;
	int i, j;

	if (n > 1)	// ���ȣ���� �������� 
	{
		v = a[n-1];  // v�� pivot value
		i = -1;		// i�� ���ʺ��� �˻��� ��ġ 
		j = n-1;    // j�� �����ʺ��� �˻��� ��ġ 
		while (true)
		{
			while (a[++i] < v);  // �ప���� ū ���� �ֳ� �˻�
			while (a[--j] > v);
			if (i >= j) break;
			t = a[i];		// �� ���� ��ȯ 
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i];   // �ప�� �ప�� ��ġ�� �ִ� ���� �ٲ� 
		a[i] = a[n-1];
		a[n-1] = t;
		QuickSort(a, i);  // ���� ���� 
		QuickSort(a+i+1, n-i-1);  // ������ ���� 
	}
}

template <class TYPE>
void QuickSort_nr(TYPE a[], int n)
{
	TYPE v, t;
	int i, j;
	int l, r;  // ���ÿ� ������ ������ ���� 
	ListStack<int> stack;
	l = 0;
	r = n-1;
	stack.Push(r);
	stack.Push(l);
	while (!stack.IsEmpty())
	{
		l = stack.Pop();
		r = stack.Pop();
		if (r-l+1 > 1)   // �������� r-l+1�� ������ ���� 
		{
			v = a[r];	// pivot value
			i = l - 1;
			j = r;
			while (true)
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			a[r] = t;
			stack.Push(r);
			stack.Push(i+1);
			stack.Push(i-1);
			stack.Push(l);
		}
	}
}

template <class TYPE>
void QuickSort_nr2(TYPE a[], int n)
{
	TYPE v, t;
	int i, j;
	int l, r;  // ���ÿ� ������ ������ ���� 
	ArrayStack<int> stack(n*2+2);
	l = 0;
	r = n-1;
	stack.Push(r);
	stack.Push(l);
	while (!stack.IsEmpty())
	{
		l = stack.Pop();
		r = stack.Pop();
		if (r-l+1 > 1)   // �������� r-l+1�� ������ ���� 
		{
			v = a[r];	// pivot value
			i = l - 1;
			j = r;
			while (true)
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			a[r] = t;
			stack.Push(r);
			stack.Push(i+1);
			stack.Push(i-1);
			stack.Push(l);
		}
	}
}

template <class TYPE>
void QuickSort_random(TYPE a[], int n)
{
	TYPE v, t;
	int i, j;
	int l, r;  // ���ÿ� ������ ������ ���� 
	ArrayStack<int> stack(n*2+2);
	l = 0;
	r = n-1;
	stack.Push(r);
	stack.Push(l);
	while (!stack.IsEmpty())
	{
		l = stack.Pop();
		r = stack.Pop();
		if (r-l+1 > 1)   // �������� r-l+1�� ������ ���� 
		{
			// ������ pivot value�� ���� 
			int pivot = int(((double)rand()/(double)RAND_MAX)*(double)(r-l)) + l;

			v = a[pivot];	// pivot value�� ��ȯ 
			a[pivot] = a[r];
			a[r] = v;

			i = l - 1;
			j = r;
			while (true)
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			a[r] = t;
			stack.Push(r);
			stack.Push(i+1);
			stack.Push(i-1);
			stack.Push(l);
		}
	}
}

template <class TYPE>
void QuickSort_median(TYPE a[], int n)
{
	TYPE v, t;
	int i, j;
	int l, r;  // ���ÿ� ������ ������ ���� 
	ArrayStack<int> stack(n*2+2);
	l = 0;
	r = n-1;
	stack.Push(r);
	stack.Push(l);
	while (!stack.IsEmpty())
	{
		l = stack.Pop();
		r = stack.Pop();
		if (r-l+1 > 3)   // �������� r-l+1�� ������ ���� 
		{
			// ��� �� ����
			int pivot = (r + l) / 2;
			// a[l], a[pivot], a[r] �� �� ���� (Bubble Sort)
			if (a[l] > a[pivot])
			{
				v = a[l]; a[l] = a[pivot]; a[pivot] = v;
			}
			if (a[pivot] > a[r])
			{
				v = a[pivot]; a[pivot] = a[r]; a[r] = v;
			}
			if (a[l] > a[pivot])
			{
				v = a[l]; a[l] = a[pivot]; a[pivot] = v;
			}	
			v = a[pivot];   // �߾Ӱ��� a[r-1]�� ��ȯ 
			a[pivot] = a[r-1];
			a[r-1] = v;

			i = l;    // ���ұ����� l+1 ~ r-2 
			j = r - 1;
			while (true)
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r-1];  // ���� 
			a[r-1] = t;      //
			stack.Push(r);
			stack.Push(i+1);
			stack.Push(i-1);
			stack.Push(l);
		} else {	// ����ũ�Ⱑ 3���� �۴ٸ� 
			// ��� �� ����
			int pivot = (r + l) / 2;
			// a[l], a[pivot], a[r] �� �� ���� 
			if (a[l] > a[pivot])
			{
				v = a[l]; a[l] = a[pivot]; a[pivot] = v;
			}
			if (a[pivot] > a[r])
			{
				v = a[pivot]; a[pivot] = a[r]; a[r] = v;
			}
			if (a[l] > a[pivot])
			{
				v = a[l]; a[l] = a[pivot]; a[pivot] = v;
			}	
		}
	}
}

template <class TYPE>
void QuickSort_sub(TYPE a[], int n)
{
	TYPE v, t;
	int i, j;
	int l, r;  // ���ÿ� ������ ������ ���� 
	ArrayStack<int> stack(n*2+2);
	l = 0;
	r = n-1;
	stack.Push(r);
	stack.Push(l);
	while (!stack.IsEmpty())
	{
		l = stack.Pop();
		r = stack.Pop();
		if (r-l+1 > 200)   // �������� r-l+1�� 200���� Ŭ���� 
		{
			// ��� �� ����
			int pivot = (r + l) / 2;
			// a[l], a[pivot], a[r] �� �� ���� 
			if (a[l] > a[pivot])
			{
				v = a[l]; a[l] = a[pivot]; a[pivot] = v;
			}
			if (a[pivot] > a[r])
			{
				v = a[pivot]; a[pivot] = a[r]; a[r] = v;
			}
			if (a[l] > a[pivot])
			{
				v = a[l]; a[l] = a[pivot]; a[pivot] = v;
			}	

			v = a[pivot];   // �߾Ӱ��� a[r-1]�� ��ȯ 
			a[pivot] = a[r-1];
			a[r-1] = v;

			i = l;    // ���ұ����� l+1 ~ r-2 
			j = r - 1;
			while (true)
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r-1];  // ���� 
			a[r-1] = t;      //
			stack.Push(r);
			stack.Push(i+1);
			stack.Push(i-1);
			stack.Push(l);
		} else {	// ����ũ�Ⱑ 200���� �۴ٸ� 
			InsertionSort(a + l, r - l + 1);
		}
	}
}

};

#endif