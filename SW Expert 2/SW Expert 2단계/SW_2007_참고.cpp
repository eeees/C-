#include <iostream>
using namespace std;
char str[31];
int get_repeating_size() 
{
	for (int size = 2; size <= 10; size++) 
	{
		bool repeating = true;
		for (int i = 0; i < size; i++) 
		{
			if (str[i] != str[i + size])
			{
				repeating = false;
				break;
			}
		}
		if (repeating) return size;
	}
	return 1;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", str);
		printf("#%d %d\n", tc, get_repeating_size());
	}
}