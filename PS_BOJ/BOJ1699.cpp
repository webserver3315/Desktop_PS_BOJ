#include <iostream>
#include <cmath>
#define MAX (int)1e5+1
using namespace std;

int mindepth = MAX;
int kazu[MAX];//제곱수로 몇 번 쓰였는지 메모용도
int sougo;//총합 몇 개의 제곱수의 합으로 나타내지는지
int n;

void DFS(int sum, int depth, int cursor) {
	if (sum >= n) {
		if (sum == n) {
			cout << depth << endl;
			if (mindepth > depth)
				mindepth = depth;
			return;
		}
		else {
			return;
		}
	}
	else{
		for (int i = cursor; i > 0; i--) {
			DFS(sum + (int)pow(i, 2), depth + 1, i);
		}
	}
}

int main() {
	cin >> n;
	DFS(0, 0, (int)sqrt(n) + 1);
	cout << mindepth << endl;
	return 0;
}