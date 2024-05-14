#include <iostream>
#include <cstdlib>

using namespace std;
#define MAXN 10
int q[MAXN];

//���Ե�i�еĵ�q[i]���Ƿ��ܰڷŻʺ�
bool place(int i)
{
	int j = 1;
	if (i == 1)
	{
		return true;
	}

	//j = 1 �� i - 1���Ѿ����ûʺ����
	while (j < i)
	{
		if ((q[j] == q[i]) || abs(q[j] - q[i]) == abs(j - i))
		{
			//�жϸûʺ��Ƿ���֮ǰ�ڷŵĻʺ�ͬ�У�λ��(j, q[j])��(i, q[i])�Ƿ���ͬһ���Խ�����
			return false;
		}
		j++;
	}
	return true;
}

//���ĸ���
int Queens(int n)
{
	//��ʼ��
	int count = 0;
	int i = 1;
	q[1] = 0;

	while (i > 0)
	{		
		//��һ��
		q[i]++;
		
		while (q[i] <= n && !place(i))
		{
			q[i]++;
		}
		
		if (q[i] <= n)
		{
			//�ҵ�һ����count+1
			if (i == n)
			{
				count++;
			}
			else
			{
				i++;
				q[i] = 0;
			}
		}
		else
		{
			//����
			i--;
		}
	}

	return count;
}

int main(void)
{
	cout << "��֤������£�" << endl;

	for (int n = 4; n <= 10; n += 2)
	{
		if (Queens(n) == 2 * Queens(n / 2))
		{
			cout << "n = " << n << "��ȷ" << endl;
		}
		else
		{
			cout << "n = " << n << "����" << endl;
		}
	}

	return 0;
}