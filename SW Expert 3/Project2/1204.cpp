//�ֺ��: �ְ� ���� �󵵼�
//100���� vector�� ���� cnt
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
			cin >> score;	//����� ���� �Է� �� ����

			//�ش� ������ vector�� ã�� count 
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