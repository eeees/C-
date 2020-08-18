//N*N크기에 M*M만큼의 합이 제일 큰 것

#include<iostream>
using namespace std;
int arr[15][15] = { 0 };
void test_arr(int i,int m,int n)
{
	int sum = 0, biggest = 0;
	for(int row=0;row<=n-m;row++){
		for(int cal=0;cal<=n-m;cal++){
			for (int k = row; k < row + m; k++) {
				for (int z =cal; z < cal + m; z++) {
					sum += arr[k][z];
				}
			}
			if (sum > biggest) {
				biggest = sum;
			}
			sum = 0;
		}
	}
	cout << "#" << i << " "<< biggest << endl;
	
	return;
}
int main(void)
{
	int t_case, n, m;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
			{
				cin >> arr[j][k];
			}
		}
		test_arr(i,m,n);

	}
	return 0;
}