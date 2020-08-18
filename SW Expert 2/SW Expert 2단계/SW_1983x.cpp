//총점 구하기->인원수만큼 오름차순해서 성적부여 ->n/10만큼 동일한 성적 받을 수 있음
//sort의 내림차순

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct node {
	int t;
	string s;
	int name;
};
vector<struct node>arr(100);
void clearArr() {
	for (int i = 0; i < 100; i++) {
		arr[i].name = 0;
		arr[i].t = 0;
	}return;
}
bool compareWeight(const node&x, const node&y) {
	return x.t > y.t;
}
void putScore(int n)
{
	int flag = 1;
	int cnt = 0;
	while (1)
	{
		if (cnt == n) {
			break;
		}
		for (int i = 0; i < n / 10; i++)
		{
			flag == 1 ? arr[cnt].s = "A+": flag == 2 ? arr[cnt].s = "A0" : flag == 3 ? arr[cnt].s = "A-" : flag == 4 ? arr[cnt].s = "B+" : flag == 5 ? arr[cnt].s = "B0" : flag == 6 ? arr[cnt].s = "B-" : flag == 7 ? arr[cnt].s = "C+" : flag == 8 ? arr[cnt].s = "C0" : flag == 9 ? arr[cnt].s = "C-" : flag == 10 ? arr[cnt].s = "D0" : arr[cnt].s = '0';
			cnt++;
		}
		flag++;

	}return;
}

int main(void)
{
	int t_case,n,k,mid,project,f,total;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++)
	{
		cin >> n >> k;
		for (int j = 0; j <n; j++)
		{
			cin >> mid >> f >> project;
			total = (mid*0.35) + (f*0.45) + (project*0.2); //총점
			arr[j].t = total;
			arr[j].name = j + 1;
		}
		sort(arr.begin(), arr.end(),compareWeight); //less가 오름차순
		putScore(n);
		for (int m = 0; m < n; m++) {
			if (arr[m].name == k) {
				cout << "#" << i << " " << arr[m].t<<" "<<arr[m].s << endl;
			}
			break;
		}
	}
	return 0;
}