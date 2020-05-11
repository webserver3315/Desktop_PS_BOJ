#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*동일한 길이로 잘라야 하므로
가능범위는 일단 0~최단값 사이이다.
이진서치 ㄱㄱ*/

#define MAX 10005

long long K, N;
long long minlan = 1, maxlan, kouhou;
vector<long long> lan;

void psearch() {
	while (minlan <= maxlan) {
		long long lankazu = 0;
		for (long long length : lan) {
			lankazu += length / kouhou;
		}
		if (lankazu < N) {
			maxlan = kouhou - 1;
			kouhou = (minlan + maxlan) / 2;
		}
		else {
			minlan = kouhou + 1;
			kouhou = (minlan + maxlan) / 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//cin >> K >> N;
	cin >> N >> K;
	for (long long i = 0; i < K; i++) {
		long long tmp;
		cin >> tmp;
		lan.push_back(tmp);
	}
	sort(lan.begin(), lan.end());
	maxlan = lan.back();
	kouhou = (minlan + maxlan) / 2;

	psearch();

	cout << kouhou << endl;

	return 0;
}