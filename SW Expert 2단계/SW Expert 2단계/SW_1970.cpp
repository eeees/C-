//���Ž����ֱ�
#include<iostream>
using namespace std;

int main(void)
{
	int t_case,money,f,t_th,th,h,t;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		cin >> money;
		//5000���� 500���� �����ؾ���!
		th = (money - ((money / 10000) * 10000)) / 1000;
		cout << "#" << i << " " << (money / 10000) / 5 << " " << (money / 10000) - 5 * ((money / 10000) / 5) << " " << th << " " << (money - ((money / 10000) * 10000) - (th * 1000)) / 100 << " " << (money % 100) * 10 << endl;
	}return 0;
}