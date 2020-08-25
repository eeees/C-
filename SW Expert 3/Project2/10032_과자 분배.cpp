#include<iostream>
#include<vector>
using namespace std;

vector<int>arr;

int minimum(int k) {
	int max = 0, min =100;

	for (int i = 0; i < k; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return max - min;
}

//7 3 ->1
void checkNum(int n, int k) {
	int num = 0, remainder=0, vec=0;
	num = n / k; //k에 공평하게 분배
	remainder = n % k; //하나씩 나눠서 분배
	
	arr.assign(k, num);

	for (int i = 0; i < remainder; i++) {
		arr[vec] = arr[vec]+1;
		vec++;
	}
}

int main(void)
{
	int t_case = 0, n = 0, k = 0,result=0;
	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		cin >> n >> k;
		checkNum(n, k);
		result=minimum(k);

		cout << "#" << i + 1 << ' ' << result << endl;
	}
	return 0;
}