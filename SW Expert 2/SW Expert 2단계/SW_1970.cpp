//돈거슬러주기
#include<iostream>
using namespace std;

int main(void)
{
	int t_case, money, f, t_th, th, h, t;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		cin >> money;

		f = money / 10000;
		th = (money / 1000) - (f * 10);
		h = (money / 100) - (f * 100) - (th * 10);
		t = (money / 10) - (f * 1000) - (th * 100) - (h * 10);

		cout << "#" << i << "\n"<< f / 5 << " " << f % 5 << " " << th / 5 << " " << th % 5 << " " << h / 5 << " " << h % 5 << " " << t / 5 << " " << t % 5 << endl;
	}return 0;
}