/*
단지번호붙이기
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
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;

/*ㅈㄴ 자주 나오면서도 bfs만 할줄알면 껌인 문제다.
FLOOD FILL의 전형인데, 여태까지 나는 BFS로만 풀었었다.
한 번 이번 기회에 DFS BFS 모두로 풀어보자.
BFS는 10분컷 ㄱㄴ이니까

변 크기는 25 이하로 보장된다.
단지의 수를 오름차순대로 출력하라.

인풋이 굉장히 더럽네; scanf로 1글자씩 받도록 하자
*/

int N;
int Map[26][26];//-1:집, 0:땅, 1부터: 단지번호
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

void BFS(int r, int c) {//r, c 로부터 BFS로 플러드필한다.
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
	//ios::sync_with_stdio(false);//scanf써서 봉인했다
	//cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			scanf("%1d", &Map[r][c]);//1글자씩 받는 것
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