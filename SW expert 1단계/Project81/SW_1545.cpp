//입력받은 문자를 -1씩 하면서 0까지 출력하기
#include<iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while (n != 0)
	{
		cout<< n << ' ';
		n -= 1;
	}
	cout << 0 << endl;
	return 0;
}