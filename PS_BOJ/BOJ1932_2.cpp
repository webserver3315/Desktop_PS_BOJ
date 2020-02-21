/*
�����ﰢ��
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

/*1 2 3 4 �� ������ ���Ҽ��� ���� �����ϴ� �����ﰢ���� �ִ�.
�� �Ǵ� ���� �ڽ����ιۿ� ���� ��, �ٴڱ��� �ִ������� �̵��ϴ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�.
�ƴ�, ��ΰ� �ƴ϶� �ִ����� ����϶�.
>>���� ���� ��θ� �ľ��ؾ������� ������� �ϳ������̶� dfs �� �ſ� ���������ٵ�, ��븸 �����ϸ� �Ǵ� �������.

500������ ������ �ﰢ���� �־�����. �ִ����� ���� 2�ʳ��� ����϶�.
������ ���� �ƴ� ������ �Էµ��� ����ȴ�.
*/

/*
�ε����� ����
		0
	  1   2
	3   4   5
  6   7   8   9
10  11  12  13  14
��Ģ ����... �̰� Ʈ���� ��� �ε����� 2���� ��Ģ�� �����ϱ� �ϴµ� ����Ʈ���� �ƴϴ�...
�ƴ� �׳� 500*500 �迭�� ������.
tri[0][0]�� [1][0], [1][1]�� �� �� ������ �Ϲ�ȭ�ϸ�
tri[r][c]�� tri[r+1][c] �Ǵ� tri[r+1][c+1]�� �� �� �ִٰ� �Ϲ�ȭ����. ��

n������ �������µ� ��� �ִ����� n�̶�� �� ��
���� �ƴ϶� �� ĭ���� �ش�ĭ���� �����ϴµ� ��� �ִ����� ������Ű��.
memo[r][c] = max( memo[r-1][c], memo[r-1][c+1] ) + tri[r][c];
DP[n]=max(for i in range n : memo[n][i])

�� ����
DP2(r,c)=max(DP2(...) �̷��� ǥ������
DP(n)=max(for c in range n : DP2(n,c))
*/

int n;
int tri[503][503];
int memo[503][503];
bool visit[503][503];

void printmemo() {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= r; c++) {
			cout << memo[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

int DP2(int r, int c) {//[r][c]���� ���µ� ��� �ִ���
	//cout << "called " << r << ' ' << c << endl;
	if (r <= 0 || c <= 0)
		return 0;
	else if (visit[r][c])
		return memo[r][c];
	else if (c == r) {
		memo[r][c] = DP2(r - 1, c - 1) + tri[r][c];
		//visit[r][c] = true;
		//return memo[r][c];
	}
	else if (c == 1) {
		memo[r][c] = DP2(r - 1, c) + tri[r][c];
		//visit[r][c] = true;
		//return memo[r][c];
	}
	else
		memo[r][c] = max(DP2(r - 1, c - 1), DP2(r - 1, c)) + tri[r][c];
	visit[r][c] = true;
	return memo[r][c];
}

int DP(int R) {//R:����(����)_������ 1������ ���, �� �Ʒ����� 2�����ʹ�.
	int maxval = 0;
	for (int c = 1; c <= R; c++) {
		if (maxval < DP2(R, c))
			maxval = DP2(R, c);
	}
	return maxval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> n;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= r; c++) {
			cin >> tri[r][c];
		}
	}
	memo[1][1] = tri[1][1];
	memo[2][1] = tri[1][1] + tri[2][1];
	memo[2][2] = tri[1][1] + tri[2][2];
	visit[1][1] = true; visit[2][1] = true; visit[2][2] = true;

	cout << DP(n) << endl;

	//printmemo();

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;
	return 0;
}