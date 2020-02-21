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


int PrintBoard() {
	for (int r = 0; r < R; r++) {
		cout << GlobalBoard[r] << endl;
	}
	return 0;
}

int GoUp(string board[], int depth) {

	for (int c = 0; c < C; c++) {
		for (int r = R-1; r >=0; r--) {
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

int GoDown(string board[], int depth) {
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

int GoLeft(string board[], int depth) {/*왼쪽으로 쏠릴 것이므로, 가로한줄씩 좌부터우로 스캔해가며 끌어당긴다.*/
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

int GoRight(string board[], int depth) {
	
	for (int r = 0; r < R; r++) {
		for (int c = C-1; c >=0; c--) {
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

string* DFS(string board[], int depth, int mode) {/*0~3: 상하좌우*/
	/*InitialBoard를 GoUp, 등의 함수에 넣으면, Game의 지역변수로 선언된 InitialBoard가 GoUp함수 내부에서 CbR로 변형되어 영향받아버리는 불상사가 발생할 듯 해서 한 번 더 설정했다.*/
	
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