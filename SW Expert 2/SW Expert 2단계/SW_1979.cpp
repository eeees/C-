//퍼즐의 각 셀 중, 흰색 부분은 1, 검은색 부분은 0 으로 주어진다.
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>arr;
int cnt = 0, n = 0, k = 0;
void tableFind(int y,int x,int t)
{
	int cntOne=1;
	if (t == 0) {
		for (int i = x + 1; i < n; i++) {

			if (arr[y][i] == 1) {
				cntOne++;
				if (i == n - 1) {
					if (cntOne == k) {
						cnt++;
					}
					cntOne = 1;
				}
			}
			else {
				if (cntOne == k) {
					cnt++;
				}
				cntOne = 1;
				break;
			}
		}
	}

	//세로
	if (t == 1) {
		for (int i = y + 1; i < n; i++) {
			if (arr[i][x] == 1) {
				cntOne++;
				if (i == n - 1) {
					if (cntOne == k) {
						cnt++;
					}
					cntOne = 1;
				}
			}
			else {
				if (cntOne == k) {
					cnt++;
				}
				cntOne = 1;
				break;
			}
		}
	}return;
}
int main(void)
{
	int t_case=0,flag=0;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++)
	{
		cin >> n >> k;
		arr.assign(n,vector<int>(n));
		for (int j = 0; j < n; j++)
		{
			for (int t = 0; t < n; t++) {
				cin >> arr[j][t];
			}
		}
		//가로 세로 따로~
		//1을 발견 후, 그 다음이 1이면 안되고 그다음이 0이면 가능!
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++) {
				if (arr[y][x] == 1 &&flag==0) {
					flag = 1;
					tableFind(y, x,0);
				}
				if (arr[y][x] == 0||x==n-1) {
					flag = 0;
				}
			}
		}
		flag = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (arr[y][x] == 1 && flag == 0) {
					flag = 1;
					tableFind(y, x, 1);
				}
				 if (arr[y][x] == 0 || y==n-1) {
					flag = 0;
				}
			}
		}
		cout << "#" << i << " " << cnt << endl;
		cnt = 0,n=0,k=0;
	}
	return 0;
}