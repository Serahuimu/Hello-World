void Swap(int* a, int* b)
{
	int Tmp = *a;
	*a = *b;
	*b = Tmp;
}

int Partition(int Array[], int Low, int High)
{
	int PivotKey = Array[Low];

	while (Low < High)
	{
		while (Low < High && PivotKey <= Array[High])
		{
			High--;
		}
		Swap(&Array[Low], &Array[High]);

		while (Low < High && PivotKey >= Array[Low])
		{
			Low++;
		}
		Swap(&Array[Low], &Array[High]);
	}

	return Low;
}

void QSort(int Array[], int Low, int High)
{
	int Pivot;

	if (Low < High)
	{
		Pivot = Partition(Array, Low, High);

		QSort(Array, Low, Pivot - 1);
		QSort(Array, Pivot + 1, High);
	}
}

int main(void)
{
	int Array[] = { 0, 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	int High = sizeof(Array) / sizeof(int) - 1;
	QSort(Array, 1, High);

	return 0;
}















//
//void Swap(int* a, int* b)
//{
//	int Tmp = *a;
//	*a = *b;
//	*b = Tmp;
//}
//
//int Partition(int Array[], int Low, int High)
//{
//	int PivotKey = Array[Low];								//ѡȡ��1��Ԫ��Ϊ����
//	
//	while (Low < High)
//	{
//		while (Low < High && Array[High] >= PivotKey)		//���ұ���С�ģ����������
//		{
//			High--;
//		}
//		Swap(&Array[High], &Array[Low]);
//
//		while (Low < High && Array[Low] <= PivotKey)		//������Ҵ�ģ��������ұ�
//		{
//			Low++;
//		}
//		Swap(&Array[High], &Array[Low]);
//	}
//
//	return Low;
//}
//
//void QSort(int Array[], int Low, int High)
//{
//	int Pivot;
//
//	if (Low < High)
//	{
//		Pivot = Partition(Array, Low, High);
//		QSort(Array, Low, Pivot - 1);			//�������
//		QSort(Array, Pivot + 1, High);				//�����ұ�
//	}
//}
//
//int main(void)
//{
//	int Array[] = { 0, 50, 10, 90, 30, 70, 40, 80, 60, 20 };
//	int High = sizeof(Array) / sizeof(int) - 1;
//	QSort(Array, 1, High);
//
//	return 0;
//}