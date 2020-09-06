//배열 다시보기 -> 런타임 에러
#include<iostream>
#include<vector>
using namespace std;
vector<int>result(10000, 0);
vector<int>arr(10000, 0);
vector<int>compare(10000, 0);

void checkBestPair(int n) {
	int num = 0, k = 10, cnt = 1,v=1;

	for (int i = 0; i < n; i++) {
		num = result[i];
		while (1) {
			if (num / k == 0) {
				break;
			}
			else {
				cnt++;
				k *= 10;
			}
		}
		if (cnt == 1) {
			break;
		}
		k =10;
		int t = cnt;
		for (int j = 1; j <= cnt; j++) {
			compare[t] = (result[i] % k) /v;
			t = t - 1;
			k *= 10;
			v *= 10;
		}

		//연속적이면서 증가하는 숫자인 경우
		for (int p = 1; p <cnt; p++) {
			int a = compare[p + 1];
			int b = compare[p];
			if ((a-b) != 1) {
				result[i] = -1;
				break;
			}
		}
	}
	return;
}

void clearVector(int n) {
	for (int i = 0; i < n; i++)
	{
		result[i] = 0;
		arr[i] = 0;
		compare[i] = 0;
	}
	return;
}
int main(void) {
	int t_case = 0, n = 0,bigger=-1;
	cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		for (int k = 0; k < n-1; k++) {
			for (int t = k+1; t < n; t++) {
				result[k] = arr[k] * arr[t];
			}
		}
		checkBestPair(n);
		for (int x = 0; x < n-1; x++) {
		
			if (result[x] > bigger) {
				bigger = result[x];
			}
		}
		cout << "#" << i + 1 << " " << bigger << endl;
		bigger = -1;
		clearVector(n);
	}
}