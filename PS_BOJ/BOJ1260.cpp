/*
DFS�� BFS

ó���� �Ｚ���׽����� T �ް� Ǯ���� �ߴµ�
�ϴ� ��Ҵ�� Ǯ�� T������ �ٲ㺸��.
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
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���

using namespace std;

/*�����Ѵ�� Ǯ��

��, �̰� ��� ��带 ��ȸ�� �ʿ�� ����. �׳� �� �̻� ������ �� ���� ������ ���� �Ǵ°Ŵ�.
�׷��ٸ�, ������ �� �� ���� ������ �ϸ� �Ǵ� �� �ƴѰ�...?
*/

int N, E, S;//����, ������, Ž�����۳���ȣ. ����� 0������ ����. 1������ �����̴�.
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

/*�����ڿ� �Ȱǵ�, �������� N���� �����ϸ� �ȵȴ�. 1000�� ��� �߿��� 2���� ���� ������ �� �յ���� ���ʿ� ��ü��ȸ��ü�� �Ұ����ϱ� �����̴�. �׷��� DFS�� �ؾ��Ѵ�. ���� �� �Լ��� ������ �ִ�.*/
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
		if (!visit[end] && Table[now][end]) {//unvisited�̸鼭 ���� �ִٸ�
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
			if (!visit[end] && Table[now][end]) {//unvisited�̸鼭 ���� �ִٸ�
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
		if (!visit[end] && Table[now][end]) {//unvisited�̸鼭 ���� �ִٸ�
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

void DFS4() {/*��͸� �̿��ؼ� �����ұ� ������ ����. �׷��� ���������� �������� �ƴ϶� ������ �����Ѹ�ŭ, ������ �����ҵ��ϱ��ѵ�*/
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

/*BFS�� ť�� �̿��ϸ� ������ ���������� ���������ϴ�. ���� ����� �ʴ�.*/
void BFS() {
	while (!BFS_Queue.empty()) {
		int now = BFS_Queue.front();
		BFS_Queue.pop();
		for (int end = 1; end <= N; end++) {
			if (!visit[end] && Table[now][end]) {//unvisited�̸鼭 ���� �ִٸ�
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