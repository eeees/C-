//�־��� N������ ���ڿ��� ������������ �����Ͽ� ���
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	vector<int>arr;
	int t_case,n,k;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		arr.clear();
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> k;
			arr.push_back(k);
		}
		sort(arr.begin(),arr.end());
		cout << "#" << i <<" ";
		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
	}return 0;
}