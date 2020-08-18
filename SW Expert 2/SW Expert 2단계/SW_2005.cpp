//파스칼 삼각형 출력
//<algorithm>에서 copy를 통한 배열 복사
//fill_n(배열명,길이,초기화할 숫자)
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10],arr2[10] = { 0 };
void pascal(int n) {
	arr[0] = 1;
	arr2[0] = 1;
	cout << arr[0] << endl;
	for (int i = 1; i <n; i++) {
		for (int j = 0; j <=i; j++) {
			arr2[j + 1] = arr[j] + arr[j + 1];
			cout << arr2[j] << " ";
		}
		copy(arr2, arr2 + 10, arr);
		cout << endl;
	}
}

int main(void)
{
	int num, t_case;
	cin >> num;
	for (int i = 1; i <=num; i++)
	{
		fill_n(arr, 10, 0);
		fill_n(arr2, 10, 0);
		cin >> t_case;
		cout << "#" << i << endl;
		pascal(t_case);
	}
	return 0;
}