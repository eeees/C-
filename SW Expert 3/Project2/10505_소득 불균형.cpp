//평균 이하의 소득을 가진 사람의 수를 출력
#include<iostream>
#include<vector>
using namespace std;

vector<int>arr;

int main(void)
{
	int t_case = 0, n = 0, num = 0, sum = 0, avg = 0,cnt=0;

	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		cin >> n;

		//vector 초기화
		arr.assign(n, 0);
	/*	for (int t = 0; t < n; t++) {
			arr[t] = 0;
		}*/

		for (int j = 0; j < n; j++) {
			cin >> num;
			arr[j] = num;
			sum = sum + num;
		}
		avg = sum / n;

		for (int y = 0; y < n; y++) {
			if (arr[y] <= avg) {
				cnt++;
			}
		}
		cout << '#' << i + 1 << ' ' << cnt << endl;
		avg = 0, sum = 0, cnt = 0;
	}
	return 0;
}