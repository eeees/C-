//10���� ���� �Է� �޾�, �ִ� ���� �ּ� ���� ������ �������� ��հ��� ����ϴ� ���α׷��� �ۼ��϶�.
//(�Ҽ��� ù° �ڸ����� �ݿø��� ������ ����Ѵ�.)
//sort�� (�迭, �迭+������ ũ��)!! ��������
//	sort(arr,arr+10);
//�ݿø� round ���� floor �ø� ceil
//cout<<fixed -> cout.precision(2);

/*
3
3 17 1 39 8 41 2 32 99 2
22 8 5 123 7 2 63 7 3 46
6 63 2 3 58 76 21 33 8 1
*/
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10] = { 0 };
int t_case = 0;
double sum = 0;

void testOperation(int i)
{
	sort(arr,arr+10);
	for (int j = 1; j < 9; j++)
	{
		sum += arr[j];
	}
	cout << fixed;
	cout.precision(1);
	sum = sum / 8;
	sum = round(sum);
	cout.precision(0);
	cout << "#" << i << " " << round(sum) << endl;
	return;
}
int main(void)
{
	cin >> t_case;
	for (int i = 1; i <= t_case; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin>>arr[j];
		}
		testOperation(i);
		sum = 0;
	}
	return 0;
}

//����!!
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector<int> v(10);
		int n;
		for (int j = 0; j < 10; j++)
			cin >> v[j];

		sort(v.begin(), v.end());
		float sum = 0;
		for (int k = 1; k < 9; k++)
			sum += v[k];

		cout << "#" << i << " " << round(sum / 8) << "\n";

	}

}

#endif