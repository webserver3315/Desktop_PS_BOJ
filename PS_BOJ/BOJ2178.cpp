/*
�̷� Ž��
*/

#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#define endl '\n'
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
typedef std::pair<int, int> P;//error C2143: ���� ���� : ';'��(��) '<' �տ� �����ϴ�.�� �߻��ϹǷ� std:: �� �ٿ��� �浹�� �����־���.
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�


using namespace std;

/*�̷ΰ� �־�����. ���� 1, ���� 0�̴�.
0�� 0���� ����. 1���� �����̴�.
1,1���� ����Ͽ� n,m���� �����ϱ� ���� ������ �ϴ� �ּ��� ĭ ���� ���϶�.

�ּ��� ĭ ���̹Ƿ� bfs�� ���� �����ϴ�.
���� DFS�� �ߴٰ� ������ �ִ� �̷θ� �Է¹޴´ٸ� �������� �� �������� �𸥴�.
Ȥ���� �������´ٰ� �ص� DFS�� �����ظ� ã�� ���ؼ��� ��� ��츦 �������߸� �� ���̴�.
���� BFS��.

�̷� ���μ��δ� ���� 100 ���ϴ�.
*/

int Map[102][102];
bool visit[102][102];
typedef pair< pair <int, int>, int > PointArrivalTime;//��ǥ r, c, �ɸ��� �ּҽð�
queue<PointArrivalTime> Queue;
int R, C;
int dr[4] = { 1,-1,0,0 }; int dc[4] = { 0,0,-1,1 };

void PrintMap() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << Map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void BFS() {
	visit[1][1] = true;
	Queue.push({ {1,1},1 });//�ɸ��ð��� �ƴ϶� ������ ĭ�� ���̹Ƿ�, ó������ ss ���ڴ� 1�� ���� �Ѵ�.
	while (!Queue.empty()) {
		/*PrintMap();
		cout << endl;*/
		PointArrivalTime nowStruct = Queue.front();
		Queue.pop();
		P Point = nowStruct.ff;
		int rr = Point.ff; int cc = Point.ss;
		if (rr == R && cc == C) {//�����ϸ�
			cout << nowStruct.ss << endl;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr > R || ccc > C || rrr <= 0 || ccc <= 0 || visit[rrr][ccc]) {
				continue;
			}
			Map[rrr][ccc] = -1;
			Queue.push({ { rrr,ccc }, nowStruct.ss + 1 });
			visit[rrr][ccc] = true;
		}
	}

	return;
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			scanf("%1d", &Map[r][c]);
			if (Map[r][c] == 0) {
				visit[r][c] = true;
			}
		}
	}

	BFS();

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}