#include <iostream>

using namespace std;

int main(void) {
	int a = 114;
	int& na = a;

	cout << "��ǰ��a = " << a << endl;
	cout << "��ǰ��na = " << na << endl;

	a = 514;
	cout << "�ı�a���a = " << a << endl;
	cout << "�ı�a���na = " << na << endl;

	na = 114514;
	cout << "�ı�na���a = " << a << endl;
	cout << "�ı�na���na = " << na << endl;

	//�����ý�����
	*&na = 1919810;
	cout << "�ı�*&na���a = " << a << endl;
	cout << "�ı�*&na���na = " << na << endl;

	return 0;
}