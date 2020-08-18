//최빈수: 최고 많은 빈도수
//100개의 vector를 만들어서 cnt
#include<iostream>
#include<vector>
using namespace std;

vector<int>frequency(101);

int findManyFrequency() 
{
	int bigger = 0, number=0;
	for (int i = 1; i <=100; i++) {
		while (frequency[i] > 0) {
			if (frequency[i] >bigger) {
				bigger = frequency[i];
				number = i;
			}
			else if (frequency[i] == bigger) {
				if (i > number) {
					number = i;
				}
			}
			break;
		}
	}
	return number;
}
void clearVector() {
	for (int i = 0; i < 101; i++) {
		frequency[i] = 0;
	}return;
}
int main(void)
{
	int t_case=0, score=0,cnt=0,result=0,num=0;
	cin >> t_case;
	for (int j = 0; j < t_case; j++) {
		cin >> num;
		for (int i = 0; i < 1000; i++) {
			cin >> score;	//띄어쓰기로 다음 입력 값 구분

			//해당 숫자의 vector를 찾아 count 
			cnt = frequency[score];
			cnt += 1;
			frequency[score] = cnt;
			cnt = 0;
		}
		result=findManyFrequency();
		cout <<"#"<<num<<' '<<result << endl;
		clearVector();
	}
	return 0;
}