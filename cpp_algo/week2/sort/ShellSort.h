#ifndef _ShellSort_h
#define _ShellSort_h

namespace cppalgo {
template <class TYPE>
void ShellSort(TYPE a[], int n)
{
	int i, j, k, h;
	TYPE v;
	for (h = n/2; h > 0; h /= 2)	
	{
		for (i = 0; i < h; i++)  // ���� 
		{
			for (j = i+h; j < n; j += h)   // j�� ���������� ��Ҹ� ����
			{
				v = a[j];
				k = j;
				while (k > h-1 && a[k-h] > v) // ������ ���� ã�� 
				{
					a[k] = a[k-h];  // �̵� 
					k -= h;
				}
				a[k] = v;		// ���� 
			}
		}
	}
}

template <class TYPE>
void ShellSort_3h(TYPE a[], int n)
{
	// h = 3*h + 1 ���� ���
	int i, j, k, h;
	TYPE v;
	for (h = 1; h < n; h = 3*h+1);   // n���� ���� �ִ��� h�� ã�´�.
	for (h /= 3; h > 0; h /= 3)
	{
		for (i = 0; i < h; i++)
		{
			for (j = i+h; j < n; j += h)
			{
				v = a[j];
				k = j;
				while (k > h-1 && a[k-h] > v)
				{
					a[k] = a[k-h];
					k -= h;
				}
				a[k] = v;
			}
		}
	}
}
};
#endif