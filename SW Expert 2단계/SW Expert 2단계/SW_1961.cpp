//주어진 행렬을 90, 180, 270 회전
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>arr;
vector<vector<int>>copy_arr;
void cycle(int n) {
	int c = 0, cnt = n-1,count=0;
	while (count!=9) {
		while (c != n) {
			for (int j = 0; j < n; j++) {
				copy_arr[j][cnt+count] = arr[c][j];
			}
			c++, cnt--;
		}

		count += 3, cnt = n - 1, c = 0;
	}
}
int main(void)
{
	int t_case, n,k,cnt=0;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		cin >> n;
		arr.assign(n, vector<int>(n));
		copy_arr.assign(n*3, vector<int>(n));
		while (cnt!=n) {
			for (int j = 0; j < n; j++) {
				cin >> arr[cnt][j];
			}
			cnt++;
		}
		cycle(n);
	}return 0;
}