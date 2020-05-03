/*
DFS와 BFS
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

/*노드 수, 엣지 수, 스타트노드번호 그리고 인접행렬이 주어진다. 노드번호는 1부터 시작이다.
DFS BFS한 순회순서를 각각 출력하라
노드는 1000, 엣지는 10000개까지 가능하다
*/

int N, E, S;
int AdjTable[1002][1002];
bool visited[1002];
queue<int> Queue_BFS;

void DFS(int nowPosition) {
	cout << nowPosition << ' ';
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && AdjTable[nowPosition][i]) {//현재노드로부터 미방문이면서 인접한 노드로만 뻗어갈 수 있다
			visited[i] = true;
			DFS(i);//애초에 visited 찍히면 해당 노드를 인자로 호출될 일이 없기에 동일한 nowPosition이 여러번 호출되거나 출력될 경우는 무시해도 된다.
		}
	}
	return;
}

void BFS(int nowPosition) {
	Queue_BFS.push(nowPosition);
	visited[nowPosition] = true;
	while (!Queue_BFS.empty()) {
		nowPosition = Queue_BFS.front();
		cout << nowPosition << ' ';
		Queue_BFS.pop();
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && AdjTable[nowPosition][i]) {
				visited[i] = true;
				Queue_BFS.push(i);
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> E >> S;
	for (int i = 0; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		AdjTable[num1][num2] = true; AdjTable[num2][num1] = true;
	}

	visited[S] = true;
	DFS(S);
	cout << endl;

	memset(visited, false, sizeof(visited));//for문 돌리는 것보다 꽤 편한 테크닉이다. 기억해두자

	BFS(S);
	cout << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}