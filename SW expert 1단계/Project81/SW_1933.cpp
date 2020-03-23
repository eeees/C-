//정수를 입력받으면 해당 정수의 약수를 오름차순으로 출력
#include<iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		if (n%i == 0)
		{
			cout << i<<' ';
		}
	}
	return 0;
}