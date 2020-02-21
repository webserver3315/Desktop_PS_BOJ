/*
외판원문제
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#define endl '\n'
using namespace std;

//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

int N, MinSum=INT_MAX;
int KyoriTable[17][17];
bool visited[17];
bool KotaeExist;

bool IsTraverseCompleted() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}

/*1번부터 N번 도시까지 순회하는 최단비용을 구해내야한다.
일단은 프림 알고리즘이 있으나, 우선 DFS로 Brute하게 구해보고 프림으로 한번 더 구해보고자 한다.
또한 시간이 나면 다익스트라 및 벨만포드, 폴로이드워셜까지 해보자.

1번나라는 일단 무조건 지나야 한다. 또한 어느 나라에서 시작하든지 상관이 없다. 따라서 1번나라부터 간다.

아, 이 문제는 다리세우기2 문제보다 약간 더 어렵다. A-B와 B-A 비용이 동일하지 않다.
그리고 또 한 부분이 다르다. 이 것은 순회문제다. 즉, 다리처럼 무작정 놓고 최소비용 계산하는게 아니라, 한붓그리기가 가능해야만 한다.*/

void DFS(int depth, int Sum) {
	cout << "호출_DFS depth, sum : " << depth << ' ' << Sum << endl;
	if (depth==N-1) {
		cout << "순회완료" << endl;
		if (!KotaeExist)
			KotaeExist = true;
		if (Sum < MinSum) {
			cout << "@@@@@@최소의 비용을 업데이트합니다. " << MinSum << " >>> " << Sum << endl;
			MinSum = Sum;
		}
		return;
	}
	for (int HajimeKuni = 1; HajimeKuni <= N; HajimeKuni++) {
		if (!visited[HajimeKuni])
			continue;
		for (int OwariKuni = 1; OwariKuni <= N; OwariKuni++) {
			if (visited[OwariKuni] || KyoriTable[HajimeKuni][OwariKuni]==0)/*이미 방문한 나라거나 자기자신이면 거른다*/
				continue;
			visited[OwariKuni] = true;
			cout << HajimeKuni << " 와 " << OwariKuni << "를 연결하는 다리를 지었습니다." << endl;
			DFS(depth + 1, Sum + KyoriTable[HajimeKuni][OwariKuni]);
			cout << HajimeKuni << " 와 " << OwariKuni << "를 연결하는 다리를 부쉈습니다." << endl;
			visited[OwariKuni] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;/*도시수 입력 및 최단거리 테이블 입력*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> KyoriTable[i][j];
		}
	}

	visited[1] = true;
	DFS(0, 0);

	if (!KotaeExist)
		cout << 0 << endl;
	else
		cout << MinSum << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}