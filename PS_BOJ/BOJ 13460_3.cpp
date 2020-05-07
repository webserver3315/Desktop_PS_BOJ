/*
����Ż��2
*/

#include <string>
#include <iostream>
using namespace std;

/*������ 4����. 10������ �� �ȳ����� �Ұ����� ����. 4�� 10���� 10��3���� 2�¿� �ٻ�, �� 10�� 6���̹Ƿ� 10�� 8�º��� �۴�. ���Ʈ���� �����̴�.*/
/*����ȭ �������� ���� �����̳� �ϴ� ����. A �����ε� �� ���̵����� ����ȭ���� �䱸�� ���� ���ҰŴ�.
��� ������ �����ڸ����� ��� '#'�� �ִٴ� ������ �����Ƿ� boundary-error ������ ���� �����Ӵ�.*/

int R, C;/*��ܺ��� 0��row, �������� 0��column*/
string GlobalBoard[11];
int IsComplete;/*0:���, 1:�������� ����, -1: �Ķ����� ����*/
bool Dekinai, Dekita;
int mincnt;

int PrintBoard() {
	for (int r = 0; r < R; r++) {
		cout << GlobalBoard[r] << endl;
	}
	return 0;
}

/*string* ��� string&����?*/
int GoUp(string* board, int depth) {

	for (int c = 0; c < C; c++) {
		for (int r = R - 1; r >= 0; r--) {
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*�����̸�, �� ������ĭ�� .�̸� ������ �����.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (rr - 1 >= 0 && board[rr - 1][cc] == '.')/*�ش� ������ �� �̻� ���ư� �� ���� ������*/ {
					--rr;
				}
				if (rr - 1 >= 0 && board[rr - 1][cc] == 'O') {
					if (color == 'B') {
						return -1;
					}
					else if (color == 'R') {
						return 1;
					}
				}
				board[r][c] = '.';
				board[rr][c] = color;
			}
		}
	}
	return 0;
}

int GoDown(string* board, int depth) {
	for (int c = 0; c < C; c++) {
		for (int r = 0; r < R; r++) {
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*�����̸�, �� ������ĭ�� .�̸� ������ �����.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (rr + 1 < R && board[rr + 1][cc] == '.')/*�ش� ������ �� �̻� ���ư� �� ���� ������*/ {
					++rr;
				}
				if (rr + 1 < R && board[rr + 1][cc] == 'O') {
					if (color == 'B') {
						return -1;
					}
					else if (color == 'R') {
						return 1;
					}
				}
				board[r][c] = '.';
				board[rr][c] = color;
			}
		}
	}
	return 0;
}

int GoLeft(string* board, int depth) {/*�������� �� ���̹Ƿ�, �������پ� �º��Ϳ�� ��ĵ�ذ��� �������.*/
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*�����̸�, �� ������ĭ�� .�̸� �·� �����.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (cc - 1 >= 0 && board[rr][cc - 1] == '.')/*�ش� ������ �� �̻� ���ư� �� ���� ������*/ {
					--cc;
				}
				if (cc - 1 >= 0 && board[rr][cc - 1] == 'O') {
					if (color == 'B') {
						return -1;
					}
					else if (color == 'R') {
						return 1;
					}
				}
				board[r][c] = '.';
				board[r][cc] = color;
			}
		}
	}
	return 0;
}

int GoRight(string* board, int depth) {

	for (int r = 0; r < R; r++) {
		for (int c = C - 1; c >= 0; c--) {
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*�����̸�, �� ������ĭ�� .�̸� ��� �����.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (cc + 1 < C && board[rr][cc + 1] == '.')/*�ش� ������ �� �̻� ���ư� �� ���� ������*/ {
					++cc;
				}
				if (cc + 1 < C && board[rr][cc + 1] == 'O') {
					if (color == 'B') {
						IsComplete = -1;
					}
					else if (color == 'R') {
						IsComplete = 1;
					}
				}
				board[r][c] = '.';
				board[r][cc] = color;
			}
		}
	}
	return 0;
}

int Game(string* board, int depth, int mode) {
	if (mode == 0) {
		int ans = GoUp(board, depth);
		return ans;
	}
	else if (mode == 1) {
		int ans = GoDown(board, depth);
		return ans;
	}
	else if (mode == 2) {
		int ans = GoLeft(board, depth);
		return ans;
	}
	else if (mode == 3) {
		int ans = GoRight(board, depth);
		return ans;
	}
	else
		cout << "ERROR ERROR ERROR ERROR ERROR" << endl;
}

int DFS(string* board, int depth, int mode) {
	if (Dekinai || Dekita) {
		return 0;
	}
	else if (depth > 10) {
		Dekinai = true;
		return 0;
	}

	string* InitialBoard = new string[R];
	for (int i = 0; i < R; i++) {
		InitialBoard[i] = GlobalBoard[i];
	}



	for (int i = 0; i < 4; i++) {
		int ans = Game(board, depth + 1, i);
		if (ans == 1) {
			Dekita = true;
			mincnt = depth;
		}
		else if (ans == -1) {
			Dekinai = true;
		}
		for (int idx = 0; idx < R; idx++) {
			GlobalBoard[idx] = InitialBoard[idx];
		}
	}
	delete InitialBoard;
	DFS(board, depth + 1, 0);

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		string tmp;
		cin >> tmp;
		GlobalBoard[r] = tmp;
	}

	DFS(GlobalBoard, 0, 0);
	if (Dekinai == true) {
		cout >> -1 >> endl;
		return 0;
	}
	else if (Dekita == true) {
		cout >> mincnt >> endl;
	}

	return 0;
}