//스도쿠에서 겹치는 숫자가 없으면 1출력
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>sudoku(9,vector<int>(9));
void clearSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = 0;
		}
	}
}
int isOk(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == sudoku[row][col] && i!=col) {
			return 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == sudoku[row][col]&&i!=row) {
			return 0;
		}
	}
	int _row = row / 3;
	int _col = col / 3;
	for (int i = _row * 3; i < (_row *3)+ 3; i++) {
		for (int j = _col * 3; j < (_col * 3) + 3; j++) {
			if (sudoku[i][j] == sudoku[row][col]&&i!=row &&j!=col) {
				return 0;
			}
		}
	}
	return 1;
}

int doSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (isOk(i, j) == 0) return 0;
		}
	}return 1;
}

int main(void)
{
	int t_case,n,result;
	cin >> t_case;
	for (int i = 1; i <= t_case; i++) {
		clearSudoku();
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cin >> sudoku[j][k];
			}
		}
		cout << "#" << i << " " << doSudoku() << endl;
	}
	return 0;
}