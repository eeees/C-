//�Է¹��� ���ڿ����� �ݺ��Ǵ� ���� ã��
//���ڿ��� ��ĭ �տ������� ��ġ�ϴ� �� ��
#include<iostream>
#include<string>
using namespace std;
int len,num,n,p=0;
string s;

int compareArr(int src, int dst);
void firstCompare(int a)
{
	for (int i = a; i < len; i++)
	{
		if (s[n] == s[i])
		{
			num++;
			p = compareArr(n + 1, i + 1);
			if (p != 0)
			{
				firstCompare(p);
			}
			return;
		}
	}
}

int compareArr(int src,int dst)
{
	//Ż������
	if (s[n]==s[dst] && s[n + 1] == s[dst + 1])
	{
		return 0;
	}
	else if (s[src] == s[dst])
	{
		num++;
		compareArr(src + 1, dst + 1);
		
	}
	else
	{
		num = 0;
		return dst;
	}
}

int main(void)
{
	int numOf;
	cin >> numOf;
	for (int i = 1; i <=numOf; i++)
	{
		num = 0;
		cin >> s;
		len = s.size();
		firstCompare(1);
		cout <<"#"<<i<<' '<< num << endl;
	}

	return 0;
}