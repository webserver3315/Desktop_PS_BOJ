#include <iostream>

#include <vector>

#include <utility>

#include <cstdlib>



using namespace std;



int sudoku[9][9];

vector<pair<int, int>> arr;

// 똑같은 숫자가 있는지 세로 검사

bool chk_vertical(int c, int num) {

	for (int r = 0; r < 9; r++) {

		if (sudoku[r][c] == num) {

			return false;

		}

	}

	return true;

}

// 가로 검사

bool chk_horizontal(int r, int num) {

	for (int c = 0; c < 9; c++) {

		if (sudoku[r][c] == num) {

			return false;

		}

	}

	return true;

}

// 3*3 네모난 모양 검사

bool chk_square(int r, int c, int num) {

	r = r / 3;

	c = c / 3;

	for (int rr = r * 3; rr < (r * 3) + 3; rr++) {

		for (int cc = c * 3; cc < (c * 3) + 3; cc++) {

			if (sudoku[rr][cc] == num) {

				return false;

			}

		}

	}

	return true;

}



void dfs(int idx) {

	// 모든 좌표에 숫자를 넣었다면 정답 출력

	if (idx == arr.size()) {

		for (int i = 0; i < 9; i++) {

			for (int j = 0; j < 9; j++) {

				cout << sudoku[i][j] << " ";

			}

			cout << "\n";

		}

		exit(0);

	}

	// 1~9까지 숫자를 넣음

	for (int num = 1; num <= 9; num++) {

		int r = arr[idx].first;

		int c = arr[idx].second;

		// 가로, 세로, 네모 모양을 검사해서 해당 숫자가 들어갈 수 있는지 확인

		if (chk_vertical(c, num) && chk_horizontal(r, num) && chk_square(r, c, num)) {

			// 들어갈 수 있다면 숫자를 넣음

			sudoku[r][c] = num;

			// 다음 좌표로 이동

			dfs(idx + 1);

			// 원상 복구

			sudoku[r][c] = 0;

		}

	}

}



int main() {

	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {

			cin >> sudoku[i][j];

			// 비어있는 칸은 좌표를 따로 저장

			if (sudoku[i][j] == 0) {

				arr.push_back({ i, j });

			}

		}

	}

	// 1~9까지 숫자를 넣음

	for (int num = 1; num <= 9; num++) {

		int r = arr[0].first;

		int c = arr[0].second;

		// 가로, 세로, 네모 모양으로 해당 num이 들어갈 수 있는지 확인

		if (chk_vertical(c, num) && chk_horizontal(r, num) && chk_square(r, c, num)) {

			sudoku[r][c] = num;

			dfs(1);

			sudoku[r][c] = 0;

		}

	}

	return 0;

}