#include<iostream>
using namespace std;

//08 09 0921
//20 09
/*
1. 4�ڸ� ���ڸ� �ΰ��� ������.
2. 13�̻��� ���ڴ� ������ YYMM���� �Ѵ�. (��, �� ������)
3. �� �� 12���ϸ� AMBIGUOUS
*/

int checkCard(int num) {
	int front=0;
	int end=0;

	front = num / 100;
	end = num % 100;


}

int main(void)
{
	int t_case = 0, num = 0, result=0;

	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		cin >> num;
		result = checkCard(num);
	}
}