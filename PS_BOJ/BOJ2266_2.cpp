#include <iostream>
#include <cmath>
#define MAX 501
using namespace std;

int mymax(int a, int b) {
	return a > b ? a : b;
}

//drop ������ ������ ��, ������ [start,drop] �� nokori-1, �ȱ����� [drop+1, end] �� nokori �� ǥ���� ������.
int recursive(int start, int end, int nokori) {
	if (nokori == 1) {//�ϳ������� ��������� �����.
		return end - start + 1;
	}
	else if (nokori == 2) {//�ΰ��� �ұ��� ����Ž���� �ؾ��Ѵ�.

	}
	else {//3�� �̻� ���Ҵٸ�, �����ϰ� ����Ž�� �񷯵� �ȴ�. �� �������� ������ 2���Ǹ�, elseif������ ����.
		return mymax(recursive(start, (start + end) / 2, nokori - 1), recursive((start + end) / 2, end, nokori));
	}
}

int n, k;
//int memo[MAX] = { 0,1,2,2,3,5, };
int memo[MAX] = { 0,1};

int dfs(int itv) {
	if (memo[itv] != 0) {
		return memo[itv];
	}
	else {
		int x;
		int minX = itv;
		for (x = 1; x <= itv; x++) {
			int rightside = dfs(itv - x);
			int maxX = mymax(x, 1 + rightside);
			if (maxX < minX) {
				cout << x << "�� �����̽����� �� �����̶�� ���" << endl;
				minX = maxX;
				memo[itv] = minX;
			}
		}
		return memo[itv];
	}
}

int dfs2(int start, int end) {//[start, end]
	int itv = end - start + 1;
	if (memo[itv] != 0) {
		return memo[itv];
	}
	else {
		int x;
		int minX = itv;
		for (x = 1; x <= itv; x++) {
			int rightside = dfs2(x + 1, end);
			int maxX = mymax(x, 1 + rightside);
			if (maxX < minX) {
				cout << x << "�� �����̽����� �� �����̶�� ���" << endl;
				minX = maxX;
				memo[itv] = minX;
			}
		}
		return memo[itv];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	dfs2(1, n);
	cout << memo[3] << endl;

	return 0;
}