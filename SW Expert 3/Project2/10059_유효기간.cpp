#include<iostream>
using namespace std;

//08 09 0921
//20 09
/*
1. 4자리 숫자를 두개로 나눈다.
2. 13이상인 숫자는 무조건 YYMM으로 한다. (앞, 뒤 따지기)
3. 둘 다 12이하면 AMBIGUOUS
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