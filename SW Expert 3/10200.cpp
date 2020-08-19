//ÇÕ »©±â n
#include<iostream>
using namespace std;

int checkAllMin(int n, int a, int b) {
	int sum = 0, result = 0;
	sum = a + b;
	result = n - sum;

	if (result > 0) {
		return 0;
	}
	
	else {
		if (result == 0) {
			return n;
		}
		else {
			return abs(result);
		}
	}
}

int checkAllMax(int n, int a, int b){
	if (a > b) {
		return b;
	}
	if (a < b) {
		return a;
	}
	else {
		return n;
	}
}

int main(void)
{
	int t_case = 0, n = 0, a = 0, b = 0,min=0,max=0;

	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		cin >> n >> a >> b;
		min=checkAllMin(n, a, b);
		max = checkAllMax(n, a, b);
		cout << "#" << i + 1 << ' ' << max<<' '<<min<< endl;
	}
	return 0;
}