#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <cstdlib>
using namespace std;
using namespace std;

int main(void)
{
	int test_case;
	int num;
	cin >> num;
	
	//vector ������ int�� �ϰ� �迭 �̸���dayOfMonth�� �Ѵ�. ũ�� ������ ���� ���� �� �ʹ�.
	vector<int> dayOfMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	//string�� �Է¹��� ���� #include<string>���ֱ�!! c++�� .h ���Ѵ�!
	string s;
	
	for (test_case = 1; test_case <= num; ++test_case)
	{
		cin >> s;
		//atoi�Լ��� �������� ��� -> #include <cstdlib>
		//���ڿ��� �Է¹޾Ƽ� int�� ���¸� �ٲپ��ַ��� �Ѵ�.
		int month = atoi(s.substr(4, 2).c_str()); //4�� �������� 2ĭ��
		int day = atoi(s.substr(6).c_str()); //6�� �������� ������

		if (month > 12 || month < 1 || day > dayOfMonth[month - 1]) {
			cout << "#" << test_case << " " << -1 << endl;
			continue;
		}
		cout << "#" << test_case << " " << s.substr(0, 4) << "/" << s.substr(4, 2) << "/" << s.substr(6) << endl;
	}
	return 0;
}