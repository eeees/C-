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
	//strcpy_s�� c���� ������ �ߴ°� ����.
	strcpy_s(ASCII_CODE, s.size() + 1, s.c_str());
	for (int i = 0; i < s.size(); i++)
	{
		cout << ((int)ASCII_CODE[i])-64<<' ';
	}
	return 0;
}
#endif

//�׳� string���� �Է¹޾Ƶ� ����ü�� �迭 ������ �Ѵ�.
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