//�Է¹��� �ҹ��� -> �빮�ڷ�
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] >=97 ? s[i] = ((int)s[i]) - 32 : s[i];
		cout << s[i];
	}
	return 0;
}