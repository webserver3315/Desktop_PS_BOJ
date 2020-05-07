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

/*간선테이블이 주어진다.
탐색을 시작할 노드의 번호가 주어진다.

방문하는 정점을 순서대로 출력하라.

방문가능한 정점이 여러개인 경우엔, 정점번호가 작은 것을 먼저 방문하고 더 이상 방문할 노드가 없을 경우 종료한다.
첫 줄에 DFS, 두 번쨰 줄에 BFS 결과를 출력한다.
정점과 간선의 개수는 1000개 이하로 보장된다.


*/

int E, V, S;//Edge, Vertex, Start노드
bool Vertex[1001][1001];
bool visit[1001];
vector<int> StepTracking;

void Vertex_Clear() {
	for (int r = 0; r < 1001; r++) {
		for (int c = 0; c < 1001; c++) {
			Vertex[r][c] = false;
		}
	}
	return;
}
void Visit_Clear() {
	for (int i = 0; i < 1001; i++) {
		visit[i] = false;
	}
	return;
}

void DFS(int depth, int imaDoko) {/*콜스택을 이용해서 푼다
			우선, 인자로 받은 현재위치하고있는노드로부터 나갈 수 있는 모든 노드에 대해 visit 때리고 전진한다.
			만일 depth가 노드수와 일치한다면 터트린다.
			*/
	if (depth == )

}

void BFS() {/*큐를 이용해서 푼다*/

}

void Solve() {
	cin >> E >> V >> S;

	for (int i = 0; i < V; i++) {
		int kara, made;
		cin >> kara >> made;
		Vertex[kara][made] = true; Vertex[made][kara] = true;
	}

	visit[S] = true;
	DFS(S);
	Visit_Clear();

	visit[S] = true;
	BFS(S);
	Visit_Clear();

	Vertex_Clear();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	int T;
	cin >> T;
	while (T--) {

	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}