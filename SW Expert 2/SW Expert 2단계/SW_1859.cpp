//입력 숫자까지의 369게임
//'-' '--' 10~1000

#if 0
#include<iostream>
using namespace std;

int  number369(int i)
{
	//해당 숫자에 3,6,9가 몇개인지 세기
	int a, b, c,cnt= 0;
	a = i / 100;
	i >= 100 ? b = (i / 10) - (a * 10) : b = i / 10;
	i >= 100 ? c = i - (b * 10) - (a * 100) : c = i - (b * 10);
	if(a == 3 || a == 6 || a == 9)
	{
		cnt++;
	}
	if (b == 3 || b == 6 || b == 9)
	{
		cnt++;
	}
	if (c == 3 || c == 6 || c == 9)
	{
		cnt++;
	}
	return cnt;
}

int main(void)
{

	int n,clap=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		clap = number369(i);
		if (clap == 0)
		{
			cout << i << ' ';
		}
		else if (clap == 1)
		{
			cout << "-" << ' ';
		}
		else if (clap == 2)
		{
			cout << "--" << ' ';
		}
		else if (clap == 3)
		{
			cout << "---" << ' ';
		}
	}
	return 0;
}    
#endif

#if 0
#include <iostream>
#include <cstdio>
using namespace std;

//숫자를 10씩 나누어가며 큰숫자->작은 숫자로 하면서 --- 를 저장
string check(int n) {
	string ret = "";
	while (n > 0) {
		int r = n % 10;
		if (r == 3 || r == 6 || r == 9) ret += "-";
		n /= 10;
	}
	return ret;
}

int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s = check(i);
		if (s == "") cout << i << " ";
		else cout << s << " ";
	}
	cout << endl;
}
#endif