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
	int front = 0;
	int end = 0;

	front = num / 100;
	end = num % 100;

	if (front < 13 && front>0 && end > 0 && end < 13) {
		return 0; //AMBIGUOS
	}
	if ((front > 12 && end < 13 && end >0) || (front == 0 && end < 13 && end>0)) {
		return 1; //YYMM
	}
	if ((end > 12 && front < 13 && front >0) || (end == 0 && front < 13 && front>0)) {
		return 2; //MMYY
	}
	else {
		return -1;
	}
}

int main(void)
{
	int t_case = 0, num = 0, result = 0;
	string answer;

	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		cin >> num;
		result = checkCard(num);
		result == 0 ? answer = "AMBIGUOUS" : result == 1 ? answer = "YYMM" : result == 2 ? answer = "MMYY" : answer = "NA";
		cout << "#" << i + 1 << ' ' << answer << endl;
	}
	return 0;
}