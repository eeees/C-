//���� 1 ���� 2 �� 3 -> �̱� ��� ���(A,B)
//���� 1>�� 3
//��3>�ָ� 2
//�ָ�2>����1
#include<iostream>
using namespace std;

int main(void)
{
	char value;
	int a, b;
	cin >> a >> b;
	a == 1 && b == 3 ? value = 'A' : a == 3 && b == 2 ? value = 'A' : a == 2 && b == 1 ? value = 'A' : value = 'B';
	cout << value << endl;
	return 0;
}