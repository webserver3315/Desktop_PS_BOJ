/*
�� ������Ʈ
�ٽ�Ǯ���. �����ϰ� ���� ������ ��ȿ���������� ��������ϰ�.
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

int T, N;
//vector<vector<int>> vvi;
vector<int> vi;
int sasumono[100005];
bool visit[100005];
bool cycled[100005];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> sasumono[i];
		}


		for (int i = 1; i <= N; i++) {
			/*if (cycled[i])
				continue;*/
			/*int next = sasumono[i];
			sasumono[i] = -1;
			while (sasumono[next] != -1) {
				int tmp = sasumono[next];
				sasumono[next] = -1;
				next = tmp;
			}
			int kaiki = next;
			next=
			while()*/
			int next = sasumono[i];
			visit[i] = true;
			while (!visit[next]) {
				visit[next] = true;
				next = sasumono[next];
			}

			//����Ŭ�� ����
			while (!cycled[next]) {
				cycled[next] = true;
				vi.push_back(next);
				next = sasumono[next];
			}
			memset(visit, false, N);
		}

		cout << N - vi.size() << endl;
	}
	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}