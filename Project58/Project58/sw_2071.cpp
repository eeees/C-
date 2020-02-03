#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	double num, sum=0;
	for (int i = 1; i <=t; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> num;
			sum += num;
		}
		cout << "#" << i << ' ' << round(sum / 10) << endl;
		sum = 0;
	}
	return 0;
}