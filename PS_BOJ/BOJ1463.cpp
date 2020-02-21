/*
1�� �����
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
#include <cstring>
#include <cstdio>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mkp(x,y) make_pair(x,y)
//pii mkpii = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

/*dp�� Ǯ�� �Ǵ� ������.
�ϴ� 3���� ������ �������� 3����, 2�� ����������� 2��, ����̸� 1�� ���� ������ 1�� �ٻ��ϵ��� �ֺ��ϸ� �ȴ�.
�׷���, �ð������� �˳�ġ �ʴ�. �Է°��� ������ 10�� 6���ε�(100��) �־����� �ð��� 2�̴�.
����Ƚ���� �ּڰ��� ����ϸ� �Ǵ� �����ε�, top down���� bottom up������ �� �Ǵ��ؾ� �� �� �ϴ�.
bottom up�� �� ���� �� �ϱ� �ѵ�
�ƴϴ�. �׳� �̰� �ε���ھƵ� Ǯ���� �ʳ�? ���ʿ� �׽�Ʈ���̽� �������� �ƴѵ�...

�ϴ� dp �Ⱦ��� Ǯ����߰ڴ�. ���� �ʿ䰡 ����δ�.

��, �̰� dp ����Ѵ�. �׸����ϰ� Ǯ���� ������ �ƴϴ�.
10 �־����� ��ġ�� 2 ������ 1 ���� 2 ������ �̷��� �Ŵ����� ���°� �ƴϴ�.
�� ������ ������ �Ŵ����� ����. �׷��Ƿ� ��� ����� ���� ������� ������ �ȵȴ�.
*/

int Solve(int N, int depth) {
	if (N == 1) {
		return depth;
	}
	if (N % 3 == 0) {
		return Solve(N / 3, depth + 1);
	}
	else if (N % 2 == 0) {
		return Solve(N / 2, depth + 1);
	}
	else {
		return Solve(N - 1, depth + 1);
	}
}

/*�ռ�Ǯ�̿��� ���������ϰ�, dp�� Ǯ��� �ߴ�. optimal substructure���� �ڸ��ϹǷ� dp�� Ǯ���� ����ȴ�.
�ϴ� visit �迭�� �ʿ��Ϸ��� �;����� �ʿ����. �׳� int�迭�� 0�̸� unvisited, ����� visited�� �ν��ϸ� �ȴ�. ���� ���� �ش� ������ ���µ� �ʿ��� ����������� ����ϸ� �ȴ�.
���� ������ ���� �ڸ��� visited��� ��������� �ƴҰ� ���ϹǷ�, �Ÿ��� �ȴ�.
�� top down�̴�.
*/

int Memo[1000002];

/*�ȵȴ�. DP_BFS�� �ٽ� Ǯ���. ���ʿ� DP�� �����ظ� ã�ƾ� �ϴµ� DFS�� ������� �ᱹ �� �Ⱦ�� �Ѵٴ� ������ ������ ���ݾ�?*/
void DP(int N) {
	if (N == 1) {
		//cout << Memo[N] << endl;
		return;
	}
	if (N % 3 == 0) {
		if (Memo[N / 3] == 0 || Memo[N / 3] > Memo[N] + 1) {
			Memo[N / 3] = Memo[N] + 1;
			DP(N / 3);
		}
	}
	if (N % 2 == 0) {
		if (Memo[N / 2] == 0 || Memo[N / 2] > Memo[N] + 1) {
			Memo[N / 2] = Memo[N] + 1;
			DP(N / 2);
		}
	}
	if (Memo[N / 3] == 0 || Memo[N / 3] > Memo[N] + 1) {
		Memo[N - 1] = Memo[N] + 1;
		DP(N / 1);
	}
	return;
}

void DP_BFS(int N) {
	queue<pii> Queue;
	Queue.push(mkp(N, 0));
	while (!Queue.empty()) {
		pii nowPosition = Queue.front();
		Queue.pop();
		int f = nowPosition.ff; int s = nowPosition.ss;
		if (f == 1) {
			//cout << s << endl;
			return;
		}

		if (f % 3 == 0) {/*bfs�� ���, ó�� ���� �ذ� �ݵ�� �����ض�� ������ �����ϹǷ� ó�� ���� 1�� ���� �������� üũ�� �� �ʿ䰡 ����*/
			if (Memo[f / 3] == 0 || Memo[f / 3] > Memo[f] + 1) {
				Memo[f / 3] = Memo[f] + 1;
				Queue.push(mkp(f / 3, s + 1));
			}
		}
		if (f % 2 == 0) {
			if (Memo[f / 2] == 0 || Memo[f / 2] > Memo[f] + 1) {
				Memo[f / 2] = Memo[f] + 1;
				Queue.push(mkp(f / 2, s + 1));
			}
		}
		if (Memo[f - 1] == 0 || Memo[f - 1] > Memo[f] + 1) {
			Memo[f - 1] = Memo[f] + 1;
			Queue.push(mkp(f - 1, s + 1));
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

	int n;
	cin >> n;
	//cout << Solve(n, 0) << endl;
	DP_BFS(n);

	cout << Memo[1] << endl;


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " sec" << endl;
	return 0;
}