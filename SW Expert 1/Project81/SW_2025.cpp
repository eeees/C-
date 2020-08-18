#include<iostream>
using namespace std;
//1~입력받은 숫자까지 더하기
int main(void)
{
	int n,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	cout << sum << endl;
	return 0;
}