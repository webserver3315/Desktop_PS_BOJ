/*
RGB�Ÿ�
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

/*R G B �� ��1�ؼ� ��ĥ�Ѵ�
������ ����Ʈ������ ����� �ٸ���
ù �ٿ� ���� ������ �־�����
�������� �ش� ���� ĥ�ϴµ� �ʿ��� ����Ʈ���� ����� �־�����
�ּҺ���� ������ ���̽��� ���� ����϶�
�� ������, ���ε��� �����ؾ��Ѵ�. ���� ���򺰷� �ּڰ���.

����� �ڿ������� ����ǹǷ�, 0�� ������ �ʿ䰡 ����. ���� visit�� Ȯ���� ���� ������ �ʿ䰡 ����.
*/

/*int memo[1005][4];//����ȣ, R G B�� ���� �� �����ϴ� �ּҺ������

memo[n][1] = 
memo[n][2] = max( memo[n-1][1] , memo[n-1][3] ) + cost[n][2]
memo[n][3] = 

*/

int N;
int memo[1005][4];
int cost[1005][4];

void printmemo() {
	for (int i = 1; i <= N; i++) {
		for (int c = 1; c <= 3; c++) {
			cout << memo[i][c] << ' ';
		}
		cout << endl;
	}
}

int DP2(int n, int c) {//����ȣ, ��
	if (n <= 0 || n > N || c <= 0 || c >= 4) {
		return 0;
	}
	if (memo[n][c]) {
		return memo[n][c];
	}
	else {
		if (c == 1) {
			memo[n][c] = min(DP2(n - 1, 2), DP2(n - 1, 3)) + cost[n][1];
		}
		else if (c == 2) {
			memo[n][c] = min(DP2(n - 1, 1), DP2(n - 1, 3)) + cost[n][2];
		}
		else if (c == 3) {
			memo[n][c] = min(DP2(n - 1, 1), DP2(n - 1, 2)) + cost[n][3];
		}
		return memo[n][c];
	}
}

int DP(int n) {
	int min = 987654321;
	for (int i = 1; i <= 3; i++) {
		int tmp = DP2(n, i);
		if (tmp < min)
			min = tmp;
	}
	//printmemo();
	return min;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int idx = 1; idx <= 3; idx++) {
			cin >> cost[i][idx];
		}
	}
	for (int i = 1; i <= 3; i++) {
		memo[1][i] = cost[1][i];
	}

	cout << DP(N) << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}