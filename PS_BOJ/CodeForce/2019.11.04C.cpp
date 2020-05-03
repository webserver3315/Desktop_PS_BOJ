/*
#598 Div3 C
*/
#include <iostream>
#include <utility>
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

#define MAX 1005

int N, M, d;//n:river m:wood
int river[MAX];
int wood[MAX];

void printriver() {
	for (int i = 1; i <= N; i++)
		cout << river[i] << ' ';
	cout << endl;
}


/*�ʱ���ġ�� 0�ε���, ���� ���Ǵ� 1������ N����, �⽾�� N+1
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M >> d;
	for (int i = 1; i <= M; i++) {
		cin >> wood[i];
	}

	int now = 0;
	int i;
	for (i = 1; i <= M /*|| now + 1 >= N + 1*/; i++) {
		int length = wood[i];
		int togo = now + d + length - 1;
		//cout << now << " ���� " << now + d << " �� ����" << endl;
		for (int idx = now + d; idx <= togo; idx++)
			river[idx] = i;
		now = togo;
		//printriver();
	}
	//cout << now << endl;

	if (i < M) {
		int lastwood = 1001;
		while (river[lastwood] != 0) {
			lastwood--;
		}
		lastwood++;
		for (; i > M; i++) {
			int length = wood[i];
			while(length--)
				river[lastwood++] = i;
		}
	}

	if (now + 1 >= N + 1) {
		cout << "YES" << endl;
		printriver();
	}
	else {
		cout << "NO" << endl;
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}