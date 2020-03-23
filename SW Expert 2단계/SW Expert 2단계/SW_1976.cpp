//두 시각을 입력받아서 더한 값출력
//1~12 , 0~59 12시간제
#include<iostream>
using namespace std;

int main(void)
{
	int t_case,hour1,hour2,min1,min2,f_hour=0,f_min=0,cnt=0;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		cin >> hour1 >> min1 >> hour2 >> min2;
		f_hour = hour1 + hour2, f_min = min1 + min2;
		while (f_min>59) {
			f_min -= 60;
			cnt++;
		}
		f_hour += cnt;
		f_hour%12!=0? f_hour = f_hour % 12 : (f_hour % 12) == 0 ? f_hour = 12:cnt=0;
		cout << "#" << i << " " << f_hour <<" "<<f_min << endl;
		cnt = 0;
	}
	return 0;
}