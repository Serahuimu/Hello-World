#include "Force.h"

void FindNumber()
{
	int x;
	//��ź�λ�ļӺͻ�
	int sum, mul;
	//�޶�xΪһ����λ��
	for (x = 100; x < 1000; x++)
	{
		//��λ���ڰ�λ && ��λ����ʮλ
		//if ((x % 100 > x / 100) && (x / 100 > x / 10 % 10))
		//��10ȡ�����λ��
		if ((x % 10 > x / 100) && (x / 100 > x / 10 % 10))
		{
			//��λ�ĺ� == ��λ�Ļ�
			sum = x / 100 + x / 10 % 10 + x % 10;
			mul = (x / 100) * (x / 10 % 10) * (x % 10);
			//Error: if (sum = mul)
			if (sum == mul)
			{
				cout << x << endl;
			}
		}
	}
}