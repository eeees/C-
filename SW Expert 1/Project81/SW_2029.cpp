#include<iostream>
using namespace std;

int main(void)
{
	int test_num, n1, n2;
	cin >> test_num;
	for (int i = 0; i < test_num; i++)
	{
		cin >> n1 >> n2;
		cout << '#' <<i+1<< ' ' << n1 / n2 <<' '<< n1 % n2 << endl;
	}
	return 0;
}