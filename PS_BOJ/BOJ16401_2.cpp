#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*������ ���̷� �߶�� �ϹǷ�
���ɹ����� �ϴ� 0~�ִܰ� �����̴�.
������ġ ����*/

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