#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	vector<int> v;
	v.reserve(8);

	for (int i = 1; i <=8; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i <8; i++)
	{
		cout << v[i] << endl;
	}
	cout << "------------" << endl;
	v.resize(10);
	v[8] = 10;
	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}