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


int PrintBoard() {
	for (int r = 0; r < R; r++) {
		cout << GlobalBoard[r] << endl;
	}
	return 0;
}

int GoUp(string board[], int depth) {

	for (int c = 0; c < C; c++) {
		for (int r = R-1; r >=0; r--) {
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

int GoDown(string board[], int depth) {
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

int GoLeft(string board[], int depth) {/*�������� �� ���̹Ƿ�, �������پ� �º��Ϳ�� ��ĵ�ذ��� �������.*/
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

int GoRight(string board[], int depth) {
	
	for (int r = 0; r < R; r++) {
		for (int c = C-1; c >=0; c--) {
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

int Game(string board[], int depth, int mode) {
	if (mode == 0) {
		GoUp(board, depth);
	}
	else if (mode == 1) {
		GoDown(board, depth);
	}
	else if (mode == 2) {
		GoLeft(board, depth);
	}
	else if (mode == 3) {
		GoRight(board, depth);
	}
	else
		return -1;
	return 0;
}

string* DFS(string board[], int depth, int mode) {/*0~3: �����¿�*/
	/*InitialBoard�� GoUp, ���� �Լ��� ������, Game�� ���������� ����� InitialBoard�� GoUp�Լ� ���ο��� CbR�� �����Ǿ� ����޾ƹ����� �һ�簡 �߻��� �� �ؼ� �� �� �� �����ߴ�.*/
	
	string* InitialBoard = board;
	if (0 == mode) {
		Game(board, depth + 1, 1);
		board = InitialBoard;
		Game(board, depth + 1, 2);
		board = InitialBoard;
		Game(board, depth + 1, 3);
		board = InitialBoard;
		return InitialBoard;
	}
	else if (1 == mode) {
		Game(board, depth + 1, 0);
		board = InitialBoard;
		Game(board, depth + 1, 2);
		board = InitialBoard;
		Game(board, depth + 1, 3);
		board = InitialBoard;
		return InitialBoard;
	}
	else if (2 == mode) {
		Game(board, depth + 1, 0);
		board = InitialBoard;
		Game(board, depth + 1, 1);
		board = InitialBoard;
		Game(board, depth + 1, 3);
		board = InitialBoard;
		return InitialBoard;
	}
	else if (3 == mode) {
		Game(board, depth + 1, 0);
		board = InitialBoard;
		Game(board, depth + 1, 1);
		board = InitialBoard;
		Game(board, depth + 1, 2);
		board = InitialBoard;
		return InitialBoard;
	}
	else {
		cerr << ERROR << endl;
		return NULL;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		string tmp;
		cin >> tmp;
		GlobalBoard[r] = tmp;
	}

	



	return 0;
}