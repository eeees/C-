#include<iostream>
using namespace std;
//2�� �Է� ���� Ƚ����ŭ ���ؼ� ���

int main(void)
{
	int n,mul=1;
	cin >> n;
	cout << mul << ' ';
	for (int i = 0; i < n; i++)
	{
		mul *= 2;
		cout << mul <<' ';
	}
	return 0;
}