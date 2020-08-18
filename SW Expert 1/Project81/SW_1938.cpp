//두 수를 입력받아서 4개의 사칙연산을 실행시킨 값을 출력
#include<iostream>
using namespace std;

int main(void)
{
	int n1, n2;
	cin >> n1 >> n2;
	cout << (n1 + n2) <<'\n'<< (n1 - n2)<<'\n' << n1 * n2<<'\n' << n1 / n2 << endl;
	return 0;
}