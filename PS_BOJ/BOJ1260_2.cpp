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

/*�������̺��� �־�����.
Ž���� ������ ����� ��ȣ�� �־�����.

�湮�ϴ� ������ ������� ����϶�.

�湮������ ������ �������� ��쿣, ������ȣ�� ���� ���� ���� �湮�ϰ� �� �̻� �湮�� ��尡 ���� ��� �����Ѵ�.
ù �ٿ� DFS, �� ���� �ٿ� BFS ����� ����Ѵ�.
������ ������ ������ 1000�� ���Ϸ� ����ȴ�.


*/

int E, V, S;//Edge, Vertex, Start���
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

void DFS(int depth, int imaDoko) {/*�ݽ����� �̿��ؼ� Ǭ��
			�켱, ���ڷ� ���� ������ġ�ϰ��ִ³��κ��� ���� �� �ִ� ��� ��忡 ���� visit ������ �����Ѵ�.
			���� depth�� ������ ��ġ�Ѵٸ� ��Ʈ����.
			*/
	if (depth == )

}

void BFS() {/*ť�� �̿��ؼ� Ǭ��*/

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