/*
SWEA A 기출
연구소
2회차
*/

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define MAX 10
#define endl '\n'
using namespace std;

vector<pii> newWallPos;
int maxAnzen;
int R, C;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int field[MAX][MAX];//0: 빈칸, 1: 벽, 2: 바이러스

//벽은 무조건 3개를 세워야 함. 안세워도 안되고 더 세워도 안됨.
//벽을 3군데 세울 때, 안전영역의 최댓값은?
//바이러스 개수는 2개 이상 10 이하이다.

/*
int 배열과 가로세로길이가 주어졌을 때
최대까지 퍼뜨려 안전영역의 크기를 반환하는 함수를 만들고,

벽을 세우는 모든 경우의 수를 DFS로 만드는 함수를 만들자.
이 경우, 전체칸의 개수가 최대 64개니까
64C3==64*63*62/2==12만가지.

1억회 내로 커버가능하다.
퍼뜨리는 것 자체는 간단한 연산이니까.
일단 뇌비우고 풀어도 풀릴 것 같다. 부대상황문제도 아니고.
*/

void printArray(int arr[][MAX]) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << arr[r][c] << ' ';
		}
		cout << endl;
	}
}

int AnzenRyouiki(int lab[][MAX]) {//R,C는 전역변수를 참조하자
	//vector나 구조체로 lab을 받으면 CallByValue를 쉽게 구현할 수 있지만, B형대비도 할 겸 CBR로 해보고자 배열을 사용했다.
	//BFS로 퍼뜨린다.
	deque<pii> viruses;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (lab[r][c] == 2) {
				viruses.push_back(mp(r, c));
			}
		}
	}
	while (!viruses.empty()) {
		pii now = viruses.front();
		viruses.pop_front();
		int r = now.ff;
		int c = now.ss;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (rr < 0 || cc < 0 || rr >= R || cc >= C || lab[rr][cc] != 0) {
				continue;
			}
			lab[rr][cc] = 2;
			viruses.push_back(mp(rr, cc));
		}
	}
	int Anzen = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (lab[r][c] == 0) {
				Anzen++;
			}
		}
	}
	return Anzen;
}//근데 이렇게 하면 전역변수field에서 복사해서 lab을 다루는게 아니라, field를 그대로 address로 다루게 되지 않나? 값만 복사해오고싶은데.

void MakeSame(int a[][MAX], int b[][MAX]) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			a[r][c] = b[r][c];
		}
	}
	return;
}

void DFS(int r, int c, int wallcnt) {
	if (wallcnt == 3) {
		int original[MAX][MAX];
		MakeSame(original, field);
		/*cout << "퍼뜨리기 전" << endl;
		printArray(original);
		cout << endl;*/
		int Anzen = AnzenRyouiki(field);
		/*cout << "퍼뜨리기 후, 안전구역은 " << Anzen << endl;
		printArray(field);
		cout << endl;*/
		MakeSame(field, original);
		if (Anzen > maxAnzen) {
			maxAnzen = Anzen;
		}
		return;
	}
	else {
		for (; r < R; r++) {
			for (; c < C; c++) {
				if (field[r][c] == 0) {
					//newWallPos.push_back(mp(r, c));
					//cout << r << ' ' << c << " 에 벽을 세움" << endl;
					field[r][c] = 1;
					DFS(r, c, wallcnt + 1);
					//newWallPos.pop_back();
					//cout << r << ' ' << c << " 의 벽을 허뭄" << endl;
					field[r][c] = 0;
				}
			}
			c = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> field[r][c];
		}
	}
	DFS(0, 0, 0);
	cout << maxAnzen << endl;

	return 0;
}//푸는데 30분15초 걸림