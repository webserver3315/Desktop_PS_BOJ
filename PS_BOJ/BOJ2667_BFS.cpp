/*
������ȣ���̱�
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
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���

using namespace std;

/*���� ���� �����鼭�� bfs�� ���پ˸� ���� ������.
FLOOD FILL�� �����ε�, ���±��� ���� BFS�θ� Ǯ������.
�� �� �̹� ��ȸ�� DFS BFS ��η� Ǯ���.
BFS�� 10���� �����̴ϱ�

�� ũ��� 25 ���Ϸ� ����ȴ�.
������ ���� ����������� ����϶�.

��ǲ�� ������ ������; scanf�� 1���ھ� �޵��� ����
*/

int N;
int Map[26][26];//-1:��, 0:��, 1����: ������ȣ
vector<int> HouseCnt;
queue<pair<int, int>> Queue_BFS;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };

void PrintMap() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << Map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void BFS(int r, int c) {//r, c �κ��� BFS�� �÷������Ѵ�.
	int VillageNumber = HouseCnt.size() + 1;
	Queue_BFS.push({ r,c });
	Map[r][c] = VillageNumber;
	int HouseNumber = 1;

	while (!Queue_BFS.empty()) {
		int rr, cc;
		rr = Queue_BFS.front().first; cc = Queue_BFS.front().second;
		Queue_BFS.pop();
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr > N || rrr<0 || ccc>N || ccc < 0 || Map[rrr][ccc] != -1)
				continue;
			Map[rrr][ccc] = VillageNumber;
			HouseNumber++;
			Queue_BFS.push({ rrr,ccc });
		}
	}
	HouseCnt.push_back(HouseNumber);
}

int main() {
	//ios::sync_with_stdio(false);//scanf�Ἥ �����ߴ�
	//cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			scanf("%1d", &Map[r][c]);//1���ھ� �޴� ��
			if (Map[r][c] == 1)
				Map[r][c] = -1;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (Map[r][c] == -1) {
				BFS(r, c);
			}
		}
	}

	//PrintMap();

	sort(HouseCnt.begin(), HouseCnt.end());
	cout << HouseCnt.size() << endl;
	for (int House : HouseCnt)
		cout << House << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}