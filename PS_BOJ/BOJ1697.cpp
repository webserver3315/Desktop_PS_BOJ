/*
���ٲ���
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


/*�����̴� �� N�� �ְ� ������ �� K�� �ִ�.
�����̴� �Ȱų� �����̵��� �����ϴ�
������ 1�ʿ� +-1ĭ �����ϴ�
�����̵��� �ݵ�� 2���� ��ǥ�� �̵��Ѵ�.
�����̰� ������ ã�� �� �ִ� ������ ���� �ð��� �� �� ���ΰ�?

������ �������� ��ǥ�� 0�̻� 10�� �����̴�.
*/

/*�������� �б��ƴٰ��� �ð��ʰ�����������. �ϴ� 2�� �ֱ� �ߴٸ�
�̰� DP�� �������ƴѰ�? 10���迭 ��ȸ�ϸ鼭. ��ȸ�� �������� �ƴϸ� Ȯ���� �б⿡ ���ؼ��� �����ϴ°� ��������.

�ϴ��� �����ظ� ã�°Ŵϱ� BFS�� �����ϰ�
DP���� �Ϲ����� BFS�� Ǯ���
*/

//int PointArrivalTime[100001];

typedef pair<int, int> PointArrivalTime;//x ��ǥ�� �����ϴµ��� �ּ� y�ʰ� �Ҹ���� ����
queue<PointArrivalTime> Queue;
int N, K;
bool visited[1000001];

void BFS() {
	Queue.push({ N,0 });
	visited[N] = true;
	while (!Queue.empty()) {
		PointArrivalTime nowPoint = Queue.front();
		Queue.pop();
		if (nowPoint.first == K) {
			cout << nowPoint.second << endl;
			//exit(0);
			break;
		}
		int f1 = nowPoint.first + 1;
		if (f1 >= 0 && f1 <= 100000 && !visited[f1]) {//���⿡ �߰������� "�湮�غ� �� ���� ��ǥ�� ��" ��� ������ �߰��Ѵٸ� �� �� ȿ�����̱� �� ���̴�.
			Queue.push({ f1,nowPoint.second + 1 });
			visited[f1] = true;
		}

		int f2 = nowPoint.first - 1;
		if (f2 >= 0 && f2 <= 100000 && !visited[f2]) {
			Queue.push({ f2,nowPoint.second + 1 });
			visited[f2] = true;
		}

		int f3 = nowPoint.first * 2;
		if (f3 >= 0 && f3 <= 100000 && !visited[f3]) {
			Queue.push({ f3,nowPoint.second + 1 });
			visited[f3] = true;
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

	cin >> N >> K;

	BFS();

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}