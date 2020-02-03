#include<iostream>
using namespace std;

int sum;
int cnt = 1;

void addToOdd(int v)
{
	if (v % 2 == 1) //È¦¼ö¸é
	{
		sum = sum + v;
	}
	return;
}

int main(void)
{
	int t;
	cin >> t;
	int *arr = (int *)malloc(sizeof(int)*t);

	for (int i = 0; i < t; i++)
	{
		arr[i] = 0;
	}

	sum = 0;
	int num;
	for (int j = 0; j < t; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> num;
			addToOdd(num);
		}
		arr[j] = sum;
		sum = 0;
	}
	for (int i = 0; i < t; i++)
	{
		cout << "#" << cnt << " " << arr[i] << endl;
		cnt++;
	}

	return 0;
}

/*
#include <iostream>
using namespace std;

int main(void)
{
	int n, x, sum;
	cin >> n;
	for (int t = 1; t <= n; t++)
	{
		sum = 0;
		for (int i = 0; i < 10; i++)
		{
			cin >> x;
			sum += x % 2 == 1 ? x : 0;
		}
		cout << "#" << t << " " << sum << endl;
	}

	return 0;
}
*/