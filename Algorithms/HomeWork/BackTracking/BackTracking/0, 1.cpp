#include <iostream>
#include <vector>

using namespace std;

//��������
int a[] = { 1, 2, 3, 4, 5 };
int n = 5, k = 9;
vector<int> minpath;	//������Ž�

//��ʾ�м�����
int minn = n;

//��ӡ��
void dispath()
{
	cout << "ѡ���Ԫ��: " << endl;
	for (int i = 0; i < minpath.size(); i++)
	{
		cout << minpath[i] << " ";
	}
	cout << "Ԫ�ظ���: " << minn;
}

//���
void dfs(vector<int> path, int sum, int start)
{
	//��ʼλ��>=n������
	if (start >= n)
	{
		return;
	}

	//��֦
	if (path.size() >= minn || sum > k)
	{
		return;
	}


	//������Ž⣬�øý��滻��ǰ��������Ž��·����ѡȡ�ĸ�����
	if (sum == k)
	{
		if (path.size() < minn)
		{
			minn = path.size();
			minpath = path;
		}
	}
	//��ѡ��ǰ��
	dfs(path, sum, start + 1);
	path.push_back(a[start]);
	//ѡ��ǰ��
	dfs(path, sum + a[start], start + 1);
}


//int main(void)
//{
//	vector<int> path;
//	dfs(path, 0, 0);
//	cout << "���Ž�: " << endl;
//	
//	dispath();
//
//	return 0;
//}