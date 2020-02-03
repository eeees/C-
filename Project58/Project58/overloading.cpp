//매개변수 선언이 다르면 함수명이 같아도 사용할 수 있다.
#include<iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int a = 3;
	int b = 2;

	char c = 'A';
	char d = 'Z';

	swap(a, b);
	swap(c, d);

	cout << a<<" "<<b << endl;
	cout << c << " " << d << endl;
	return 0;
}
