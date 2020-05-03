/*
�� ������Ʈ
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
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

#define StuMax 100005

int T, N;
int sasu[StuMax];
bool visit[StuMax];
bool done[StuMax];
int cnt;

void DFS(int stu) {//done �� stu�� ������ �ʴ´ٴ� ������ �Ǿ��ִٴ� ������ §��.
	visit[stu] = true;
	int next = sasu[stu];
	/*if (done[stu]) {
		cout << stu << "�� done �Ǿ����Ƿ� �Ÿ���" << endl;
		return;
	}*/
	if (!visit[next]) {//unvisited��
		cout << stu << "���� " << next << " �� ����" << endl;
		DFS(next);
	}
	else if(!done[next]){//visited && undone
		/*int originnext = next;
		for (next = sasu[next]; next != originnext; next = sasu[next]) {
			cout << next << "������ ī��Ʈ�ϰ� " << sasu[next] << " �� ����" << endl;
			cnt++;
		}
		cnt++;*/
		for (int i = next; i != stu; i = sasu[i]) {
			cnt++;
		}
		cnt++;
	}
	cout << stu << "�� done ���ȴ�" << endl;
	done[stu] = true;//����Ŭ�̵� �ƴϵ�, �� �� �湮������ ����Ȯ���ص� ����Ŭ���ΰ���� �����ϹǷ� �� �̻� Ȯ���� ���� ����
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		cin >> N;
		memset(visit + 1, false, N);
		memset(done + 1, false, N);
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cin >> sasu[i];
		}

		for (int i = 1; i <= N; i++) {
			if(!done[i])
				DFS(i);
		}
		cout << N - cnt << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}