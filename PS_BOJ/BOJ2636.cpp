/*
ġ��
*/
#include <iostream>
#include <utility>
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
using namespace std;
#define endl '\n'
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0.0, -1,1 };
int R, C;
int cheese[105][105] = { 2, };


/*�����ؾ��� ����, ����� ���ۿ� ���Ⱑ ���ٰ� �ľ��Ѵٴ� ���̴�.

���� �ް�, �ܺΰ��⸦ 2�� FLOOD FILL �ؼ� �ʱ�ȭ�Ѵ�.
�ܺΰ��������� ��� ������ ���ΰ�?

�� step�� �ʸ��� �ݺ��ϵ��� ����

���� flood fill
2�� ������ ġ�� ���� ť�� �ֱ�
ť�� ����ִ� ġ�� ���� ����
�ݺ�

*/

void OxygenFlood() {//�̰� �ð����� �ƴ϶� ��� �̷�������Ѵ�.
	queue<pii> closedoxygen;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (cheese[r][c] != 2)
				continue;
			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i]; int cc = c + dc[i];
				if (rr >= R || cc >= C || rr < 0 || cc < 0 || cheese[rr][cc] != 0)
					continue;

				cheese[rr][cc] = 2;
				closedoxygen.push(mp(rr, cc));
				while (!closedoxygen.empty()) {
					int rrr = closedoxygen.front().first; int ccc = closedoxygen.front().second;
					closedoxygen.pop();
					for (int ii = 0; ii < 4; ii++) {
						int rrrr = rrr + dr[ii]; int cccc = ccc + dc[ii];
						if (rrrr >= R || cccc >= C || rrrr < 0 || cccc < 0 || cheese[rrrr][cccc] != 0)
							continue;
						cheese[rrrr][cccc] = 2;
						closedoxygen.push(mp(rrrr, cccc));
					}
				}

			}
		}
	}

}

void killAdj() {
	queue<pair<int,int>> killqueue;//���� ť�� at ������ �ȵȴٴ°� ó���˾Ҵ�
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (cheese[r][c] != 1)
				continue;
			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i]; int cc = c + dc[i];
				if (rr >= R || cc >= C || rr < 0 || cc < 0 || cheese[rr][cc] != 2)
					continue;
				killqueue.push({ r,c });
			}
		}
	}
	for (int idx = 0; idx < killqueue.size(); idx++) {
		pii soonkill = killqueue.at(idx);
		cheese[soonkill.ff][soonkill.ss] = 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; r++) {
			cin >> cheese[r][c];
		}
	}
	int sec = 0;


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}