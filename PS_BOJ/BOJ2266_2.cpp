#include <iostream>
#include <cmath>
#define MAX 501
using namespace std;

int mymax(int a, int b) {
	return a > b ? a : b;
}

//drop 층에서 떨궜을 때, 깨지면 [start,drop] 및 nokori-1, 안깨지면 [drop+1, end] 및 nokori 의 표본을 가진다.
int recursive(int start, int end, int nokori) {
	if (nokori == 1) {//하나남으면 선형말고는 답없다.
		return end - start + 1;
	}
	else if (nokori == 2) {//두개면 소극적 이진탐색을 해야한다.

	}
	else {//3개 이상 남았다면, 과감하게 이진탐색 찔러도 된다. 그 과정에서 깨져서 2개되면, elseif문으로 간다.
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
				cout << x << "를 슬라이스했을 때 최적이라고 경신" << endl;
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
				cout << x << "를 슬라이스했을 때 최적이라고 경신" << endl;
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