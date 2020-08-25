#include<iostream>
#include<vector>
using namespace std;

int hour = 0, min = 0;


int main(void)
{
	int t_case = 0, k = 0;

	cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		cin >> k;
		hour = (k / 30);
		min = (k % 30) * 2;
		
		cout << "#" << i + 1 << ' ' << hour << ' ' << min << endl;
	}
	return 0;
}