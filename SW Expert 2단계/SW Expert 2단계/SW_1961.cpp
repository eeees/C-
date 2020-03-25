//주어진 행렬을 90, 180, 270 회전
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>arr;
int main(void)
{
	int t_case, n,k,cnt=0;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		cin >> n;
		arr.assign(n, vector<int>(n));
		while (cnt!=n) {
			for (int j = 0; j < n; j++) {
				cin >> arr[cnt][j];
			}
			cnt++;
		}

	}return 0;
}