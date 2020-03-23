/*
#++++
+#+++
++#++
+++#+
++++#
*/
#include<iostream>
using namespace std;

int main(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << (i == 0 ? "#++++":i==1?"+#+++":i==2?"++#++":i==3?"+++#+":i==4?"++++#":"-1") << endl;
	}
	return 0;
}