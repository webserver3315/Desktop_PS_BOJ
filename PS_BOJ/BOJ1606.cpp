/*
���̷���
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
using namespace std;
#define endl '\n'
//#define ff first
//#define ss second
//typedef std::pair <int, int> P;//error C2143: ���� ���� : ';'��(��) '<' �� �߻��ϹǷ� std:: �� �ٿ��� �浹�� �����־���.
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

/*�̹��� dfs�� Ǯ���. �̰� BFS�� Ǯ�� 10���Ƴ��ϱ�.
100�� ������ ��ǻ�� ���� �־�����, ��°�ٺ��ʹ� ������, �� �������ʹ� ������ �־�����.
�׻� 1����ǻ�Ͱ� ù ������ �����ȴ�.
1����ǻ�ʹ� �� ���� ��ǻ�Ϳ� ���̷����� �ű�°�?
*/

int N, E;
bool AdjTable[102][102];
bool visited[102] = { true, };//1������ ������ ����
int HowMany;

void DFS(int kara) {
	HowMany++;
	for (int made = 1; made <= N; made++) {//made==�ު�
		if (!visited[made] && AdjTable[kara][made]) {//�ȵ鷶�� ������ ��忡 ����
			visited[made];
			DFS(made);
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

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		AdjTable[num1][num2] = true; AdjTable[num2][num1] = true;
	}

	DFS(1);

	cout << HowMany << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}