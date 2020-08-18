#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	int a[100];
	int N, K;
	int mid, fin, hom;
	char grades[10][3] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &mid, &fin, &hom);
			a[i] = mid * 35 + fin * 45 + hom * 20;
		}
		int k_score = a[K - 1];
		int k_rank;
		sort(a, a + N);

		for (int i = 0; i < N; i++) {
			if (a[i] == k_score) {
				k_rank = N - 1 - i;
				break;
			}
		}
		printf("#%d %s\n", tc, grades[10 * k_rank / N]);
	}
}