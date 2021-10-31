#ifndef _SelectionSort_h
#define _SelectionSort_h

namespace cppalgo {

template <class TYPE>
void SelectionSort(TYPE a[], int n)
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
	}
}
};
#endif