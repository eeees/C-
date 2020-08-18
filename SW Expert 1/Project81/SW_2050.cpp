#if 0
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

int main(void)
{
	vector<char>v;
	string s;
	cin >> s;
	char *ASCII_CODE = new char[s.size() + 1];
	//strcpy_s가 c언어라서 오류가 뜨는거 같다.
	strcpy_s(ASCII_CODE, s.size() + 1, s.c_str());
	for (int i = 0; i < s.size(); i++)
	{
		cout << ((int)ASCII_CODE[i])-64<<' ';
	}
	return 0;
}
#endif

//그냥 string으로 입력받아도 그자체가 배열 역할을 한다.
#if 1
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] - 64 << ' ';
	}
	return 0;
}
#endif