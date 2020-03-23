#include<iostream>
using namespace std;
//2를 입력 받은 횟수만큼 곱해서 출력

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