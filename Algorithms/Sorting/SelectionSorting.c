#include "Sorting.h"

void SelectionSort(DataType Array[], int Length)
{
	int i, j, min;

	for (i = 0; i < Length; i++)
	{
		min = i;
		for (j = i + 1; j < Length; j++)
		{
			if (Array[j] < Array[min])		//��min�����Сֵ
			{
				min = j;
			}
		}
		Swap(&Array[i], &Array[min]);	//����С�ķ��ڵ�ǰ���е���ǰ��

		for (int k = 0; k < Length; k++)
		{
			printf("%d ", Array[k]);
		}
		printf("\n");
	}


}