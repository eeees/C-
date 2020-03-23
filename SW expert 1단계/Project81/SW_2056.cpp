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
	
	//vector 형식을 int로 하고 배열 이름을dayOfMonth로 한다. 크기 지정은 따로 안한 듯 싶다.
	vector<int> dayOfMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	//string을 입력받을 때는 #include<string>해주기!! c++은 .h 안한다!
	string s;
	
	for (test_case = 1; test_case <= num; ++test_case)
	{
		cin >> s;
		//atoi함수를 쓰기위한 헤더 -> #include <cstdlib>
		//문자열을 입력받아서 int로 형태를 바꾸어주려고 한다.
		int month = atoi(s.substr(4, 2).c_str()); //4번 지점부터 2칸만
		int day = atoi(s.substr(6).c_str()); //6번 지점부터 끝까지

		if (month > 12 || month < 1 || day > dayOfMonth[month - 1]) {
			cout << "#" << test_case << " " << -1 << endl;
			continue;
		}
		cout << "#" << test_case << " " << s.substr(0, 4) << "/" << s.substr(4, 2) << "/" << s.substr(6) << endl;
	}
	return 0;
}