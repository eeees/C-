//가위 1 바위 2 보 3 -> 이긴 사람 출력(A,B)
//가위 1>보 3
//보3>주먹 2
//주먹2>가위1
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