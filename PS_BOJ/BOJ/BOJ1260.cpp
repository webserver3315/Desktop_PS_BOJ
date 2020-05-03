/*
DFS와 BFS

처음엔 삼성역테식으로 T 받고 풀려고 했는데
일단 평소대로 풀고 T식으로 바꿔보자.
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

/*생각한대로 풀자

아, 이거 모든 노드를 순회할 필요는 없다. 그냥 더 이상 전진할 수 없을 때까지 가면 되는거다.
그렇다면, 스택이 빌 때 까지 가도록 하면 되는 것 아닌가...?
*/

int N, E, S;//노드수, 엣지수, 탐색시작노드번호. 참고로 0번노드는 없다. 1번부터 시작이다.
bool Table[1002][1002];
bool visit[1002];
vector<int> DFS_Answer;
vector<int> DFS_Stack;
bool DFS_Finished;
vector<int> BFS_Answer;
queue<int> BFS_Queue;
bool BFS_Finished;

void Visit_Clear() {
	for (auto& a : visit)
		a = false;
	return;
}

/*한참뒤에 안건데, 종료조건 N으로 설정하면 안된다. 1000개 노드 중에서 2개만 연결 나머지 다 왕따라면 애초에 전체순회자체가 불가능하기 때문이다. 그러나 DFS는 해야한다. 따라서 이 함수는 결점이 있다.*/
void DFS(int depth, int now) {
	if (depth == N) {
		if (DFS_Finished)
			return;
		for (int i : DFS_Answer)
			cout << i << ' ';
		cout << endl;
		DFS_Finished = true;
		return;
	}
	for (int end = 1; end <= N; end++) {
		if (!visit[end] && Table[now][end]) {//unvisited이면서 길이 있다면
			visit[end] = true;
			DFS_Answer.push_back(end);
			DFS(depth + 1, end);
			visit[end] = false;
			DFS_Answer.pop_back();
		}
	}
	return;
}

void DFS2() {
	while (!DFS_Stack.empty()) {
		int now = DFS_Stack.back();
		DFS_Stack.pop_back();
		for (int end = N; end > 0; end--) {
			if (!visit[end] && Table[now][end]) {//unvisited이면서 길이 있다면
				visit[end] = true;
				DFS_Stack.push_back(end);
				DFS_Answer.push_back(end);
			}
		}
	}
	for (int tmp : DFS_Answer)
		cout << tmp << ' ';
	cout << endl;
	return;
}

void DFS3() {
	int now = DFS_Stack.back();
	DFS_Stack.pop_back();
	DFS_Answer.push_back(now);
	for (int end = 1; end <= N; end++) {
		if (!visit[end] && Table[now][end]) {//unvisited이면서 길이 있다면
			visit[end] = true;
			DFS_Stack.push_back(end);
			DFS3();
		}
	}

	if (DFS_Stack.empty()) {
		for (int tmp : DFS_Answer)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	return;
}

void DFS4() {/*재귀를 이용해서 구현할까 스택을 쓸까. 그런데 종료조건이 닿을때가 아니라 소진이 적절한만큼, 스택이 적절할듯하긴한데*/
	while (!DFS_Stack.empty()) {
		int now = DFS_Stack.back();
		DFS_Stack.pop_back();
		if (visit[now])
			continue;
		for (int end = N; end > 0; end--) {
			if (!visit[end] && Table[now][end]) {
				visit[end] = true;
				
			}
		}


	}
}

void DFS_Fuck(int now) {
	cout << now << ' ';
	for (int to = 1; to <= N; to++) {
		if (!visit[to] && Table[now][to]) {
			visit[to] = true;
			DFS_Fuck(to);
		}
	}
	return;
}

/*BFS는 큐를 이용하면 굉장히 직관적으로 구현가능하다. 전혀 어렵지 않다.*/
void BFS() {
	while (!BFS_Queue.empty()) {
		int now = BFS_Queue.front();
		BFS_Queue.pop();
		for (int end = 1; end <= N; end++) {
			if (!visit[end] && Table[now][end]) {//unvisited이면서 길이 있다면
				BFS_Queue.push(end);
				BFS_Answer.push_back(end);
				visit[end] = true;
			}
		}
	}
	for (int node : BFS_Answer)
		cout << node << ' ';
	cout << endl;

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> E >> S;
	for (int i = 0; i < E; i++) {
		int start; int end;
		cin >> start >> end;
		Table[start][end] = true; Table[end][start] = true;
	}

	/*visit[S] = true;
	DFS_Stack.push_back(S);
	DFS_Answer.push_back(S);
	DFS4();*/

	visit[S] = true;
	DFS_Fuck(S);
	cout << endl;

	Visit_Clear();

	visit[S] = true;
	BFS_Queue.push(S);
	BFS_Answer.push_back(S);
	BFS();


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}