/*
구슬탈출2
*/

#include <string>
#include <iostream>
using namespace std;

/*조작은 4가지. 10번내로 답 안나오면 불가판정 ㄱㄴ. 4의 10승은 10의3승의 2승에 근사, 즉 10의 6승이므로 10의 8승보다 작다. 브루트포스 ㄱㄴ이다.*/
/*최적화 생각하지 말고 구현이나 일단 하자. A 수준인데 이 난이도에서 최적화까지 요구는 절대 안할거다.
모든 보드의 가장자리에는 모두 '#'이 있다는 조건이 있으므로 boundary-error 에서는 비교적 자유롭다.*/

int R, C;/*상단부터 0번row, 좌측부터 0번column*/
string GlobalBoard[11];
int IsComplete;/*0:평시, 1:빨간구슬 골인, -1: 파란구슬 골인*/
bool Dekinai, Dekita;
int mincnt;

int PrintBoard() {
	for (int r = 0; r < R; r++) {
		cout << GlobalBoard[r] << endl;
	}
	return 0;
}

/*string* 대신 string&쓸까?*/
int GoUp(string* board, int depth) {

	for (int c = 0; c < C; c++) {
		for (int r = R - 1; r >= 0; r--) {
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*구슬이면, 또 상인접칸이 .이면 상으로 끌어낸다.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (rr - 1 >= 0 && board[rr - 1][cc] == '.')/*해당 구슬이 더 이상 나아갈 수 없을 때까지*/ {
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
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*구슬이면, 또 상인접칸이 .이면 상으로 끌어낸다.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (rr + 1 < R && board[rr + 1][cc] == '.')/*해당 구슬이 더 이상 나아갈 수 없을 때까지*/ {
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

int GoLeft(string* board, int depth) {/*왼쪽으로 쏠릴 것이므로, 가로한줄씩 좌부터우로 스캔해가며 끌어당긴다.*/
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*구슬이면, 또 좌인접칸이 .이면 좌로 끌어낸다.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (cc - 1 >= 0 && board[rr][cc - 1] == '.')/*해당 구슬이 더 이상 나아갈 수 없을 때까지*/ {
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
			if (board[r][c] == 'B' || board[r][c] == 'R') {/*구슬이면, 또 우인접칸이 .이면 우로 끌어낸다.*/
				char color = board[r][c];
				int rr = r;
				int cc = c;
				while (cc + 1 < C && board[rr][cc + 1] == '.')/*해당 구슬이 더 이상 나아갈 수 없을 때까지*/ {
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