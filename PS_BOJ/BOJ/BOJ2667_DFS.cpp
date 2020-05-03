/*
������ȣ���̱�

FLOOD FILL�� �̹��� DFS�� Ǯ���
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

void DFS(int r, int c) {
	//PrintMap();
	//cout << endl;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i]; int cc = c + dc[i];
		if (rr > N || cc > N || rr < 0 || cc < 0 || Map[rr][cc] != -1) {
			continue;
		}
		Map[rr][cc] = HouseCnt.size();
		HouseCnt.back()++;
		DFS(rr, cc);
	}
	return;
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

	/*int VillageNumber = HouseCnt.size() + 1;
	Map[r][c] = VillageNumber;
	HouseCnt[VillageNumber - 1]++;*/

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (Map[r][c] == -1) {
				HouseCnt.push_back(1);
				Map[r][c] = HouseCnt.size();
				DFS(r, c);
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