//회문이면 1출력 아니면 0출력
/*
3
level
samsung
eye
#1 1
#2 0
#3 1
단어 길이는 3~10
*/
#include<iostream>
#include<string>
using namespace std;

int isPalindrome(string s)
{
	int len = s.size();
	int mid = len/2;
	int cnt = 0,check=0,i=0,j=len-1;
	
	while (1) {
		if ((len%2==0)&&i > mid-1 &&j < mid)
		{
			break;
		}
		if ((len % 2 == 1) && i > mid && j < mid)
		{
			break;
		}
		if (s[i] == s[j])
		{
			cnt++;
		}
		i++;
		j--;
	}
	(len % 2 == 0) && (cnt == mid) ? check = 1 : (len % 2 == 1) && (cnt == (mid + 1)) ? check = 1 : check = 0;
	return check;
}

int main(void)
{
	int t_case;
	cin >> t_case;
	string s;
	for (int i = 1; i <= t_case; i++)
	{
		cin >> s;
		cout<<"#"<<i<<" "<< isPalindrome(s)<<endl;
	}
	return 0;
}