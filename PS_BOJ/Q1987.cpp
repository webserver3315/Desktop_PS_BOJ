/*
���ĺ�
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int r, c;/*row, column*/
vector<string> board;
bool visited[26];

int dr[4] = { -1,1,0,0 };/*�����¿�*/
int dc[4] = { 0,0,-1,1 };
int maxcnt=1;

bool IsInBound(int rr, int cc) {
	if (rr < 0 || rr >= r || cc < 0 || cc >= c) {/*��ܶ��*/
		return false;
	}
	else
		return true;
}

int DFS(int rr, int cc, int cnt) {
	if (rr < 0 || rr >= r || cc < 0 || cc >= c) {/*���� ��ܶ��*/
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		int rrr = rr + dr[i];
		int ccc = cc + dc[i];
		if (IsInBound(rrr,ccc)) {/*��� ���� ��ܰ� �ƴ϶��*/
			if (visited[board[rrr][ccc] - 'A'] == true) {/*���� ���ڸ� �Ÿ���*/
				continue;
			}
			cnt++;
			if (maxcnt < cnt)
				maxcnt = cnt;
			visited[board[rrr][ccc] - 'A'] = true;
			DFS(rrr, ccc, cnt);
			cnt--;
			visited[board[rrr][ccc] - 'A'] = false;
		}
		else {/*��� ���� ��ܸ� �Ÿ���*/
			continue;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str_tmp;
		cin >> str_tmp;
		board.push_back(str_tmp);
	}
	/*
	board[r][c]= r��° �ο�, c��° ����
	*/
	visited[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << maxcnt << endl;
	return 0;
}