/*
C++ 삼항연산자 는 if ~ else 문을 대신하여 사용할 수 있는 연산자를 말합니다.
조건연산자 또는 삼항연산자 라고 불립니다.

‘조건’ ? ‘A’ : ‘B’
위와 같은 형태로 사용합니다.
조건이 참이면 A를 반환하고 조건이 거짓이면 B를 반환합니다.
*/
#include<iostream>
using namespace std;

int main(void)
{
	int sum = 0;
	int sum2 = 0;
	for (int i = 1; i <=10; i++)
	{
		//sum += i%2; //sum = sum + (i%2);
		//sum2 += i; // sum = sum + i;
		if (i % 2 == 1)
		{
			sum = sum + i;
		}
		else
		{
			sum = sum + 0;
		}
		//sum += i % 2 == 1 ? i : 0;
	}
	cout << sum << endl;
	return 0;
}

