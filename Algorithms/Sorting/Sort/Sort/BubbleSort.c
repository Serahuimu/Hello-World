#include "Sorting.h"

void BubbleSort(DataType Array[], int Length)
{
	int i, j;

	for (i = 0; i < Length; i++)
	{
		//��j��j+1�Ƚϣ�j = Length - 2, j + 1 = Length - 1�����������һλ��
		//�������-1����Խ��������
		for (j = 0; j < Length - 1 - i; j++)		
		{
			if (Array[j] > Array[j + 1])
			{
				Swap(&Array[j], &Array[j + 1]);
			}
		}

		for (int k = 0; k < Length; k++)
		{
			printf("%d ", Array[k]);
		}
		printf("\n");
	}

	////����һ�ˣ�������һ����������ĩβ���ڶ����ٴδ���ʼλ�ÿ�ʼ���ȵ���Length - 1 - 1����
	////�����˵�Length - 1 - 1 - 1����
	//for (i = 0; i < Length - 1; i++)
	//{
	//	if (Array[i] > Array[i + 1])
	//	{
	//		Swap(&Array[i], &Array[i + 1]);
	//	}
	//}
}