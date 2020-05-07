#include <iostream>
#include <queue>
#define MAX 1501
using namespace std;
//병합정렬?
int N;
priority_queue<int> pqarr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			pqarr[j].push(tmp);
		}
	}

	for (int i = 0; i < N - 1; i++) {

	}

	return 0;
}