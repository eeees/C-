/*
C++ ���׿����� �� if ~ else ���� ����Ͽ� ����� �� �ִ� �����ڸ� ���մϴ�.
���ǿ����� �Ǵ� ���׿����� ��� �Ҹ��ϴ�.

�����ǡ� ? ��A�� : ��B��
���� ���� ���·� ����մϴ�.
������ ���̸� A�� ��ȯ�ϰ� ������ �����̸� B�� ��ȯ�մϴ�.
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

