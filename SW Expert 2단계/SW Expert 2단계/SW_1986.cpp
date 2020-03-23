//1부터 N까지의 숫자에서 홀수는 더하고 짝수는 뺐을 때 최종 누적된 값을 구해보자.
/*
입력
2
5
6
출력
#1 3
#2 -3
*/
#include<iostream>
using namespace std;

int main(void)
{
	int t_case=0,num=0,sum=0;
	cin >> t_case;
	for (int j = 1; j <= t_case; j++)
	{
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			(i % 2 == 1) ? sum += i : (i % 2 == 0) ? sum -= i : sum += 0;
		}
		cout << "#" << j << " " << sum << endl;
		sum = 0;
	}
	return 0;
}