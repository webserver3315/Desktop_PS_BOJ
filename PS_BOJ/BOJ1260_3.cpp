/*
DFS�� BFS
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

/*��� ��, ���� ��, ��ŸƮ����ȣ �׸��� ��������� �־�����. ����ȣ�� 1���� �����̴�.
DFS BFS�� ��ȸ������ ���� ����϶�
���� 1000, ������ 10000������ �����ϴ�
*/

int N, E, S;
int AdjTable[1002][1002];
bool visited[1002];
queue<int> Queue_BFS;

void DFS(int nowPosition) {
	cout << nowPosition << ' ';
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && AdjTable[nowPosition][i]) {//������κ��� �̹湮�̸鼭 ������ ���θ� ��� �� �ִ�
			visited[i] = true;
			DFS(i);//���ʿ� visited ������ �ش� ��带 ���ڷ� ȣ��� ���� ���⿡ ������ nowPosition�� ������ ȣ��ǰų� ��µ� ���� �����ص� �ȴ�.
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

	memset(visited, false, sizeof(visited));//for�� ������ �ͺ��� �� ���� ��ũ���̴�. ����ص���

	BFS(S);
	cout << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}