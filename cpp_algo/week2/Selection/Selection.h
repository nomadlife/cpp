#ifndef _Selection_h
#define _Selection_h

namespace cppalgo 
{
template <class TYPE>
TYPE Select_Linear(TYPE a[], int n, int k)
{
	TYPE min;		// �ּҰ� ����
	int minindex;   // �ּҰ� �ε��� ���� 
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		minindex = i;	// �ּҰ��� �ʱ⼳�� 
		min = a[i];
		for (j = i + 1; j < n; j++)  // i������ �ּҰ��� ã�� 
		{
			if (min > a[j])  // �� ���� ���̸� �ٲ�
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i];  // i�װ� min���� ��ȯ 
		a[i] = min;

		if (i == k)
			return min;
	}
	throw "Invalid k";
}

template <class TYPE>
TYPE Select_Partition(TYPE a[], int n, int k)
{
	TYPE v, t;
	int i, j, l, r;
	l = 1;
	r = n;
	while (r > l)
	{
		v = a[r];
		i = l-1;
		j = r;
		while (true)
		{
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j) break;
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
		t = a[i]; a[i] = a[r]; a[r] = t;

		if (i >= k) r = i - 1;
		if (i <= k) l = i + 1;
	}

	return a[k];
}
};

#endif