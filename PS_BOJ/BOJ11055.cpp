#include <iostream>
#define MAX (int)1e4+1
using namespace std;

int N;
int maxmemo;
int val[MAX];
int memo[MAX];

//�Ʒ� DP�Լ��� 38 19 �� �������� 19�� �����θ� memo�� ���� ���ϰ� �ٷ� �Լ��� �ٸ� loop�� �Ѿ������ ������ �ִ�.
void DP_BU(int k) {//BottomUp DP
	for (int n = k; n < N; n++) {
		for (int i = n - 1; i >= 0; i--) {
			if (val[i] < val[n]) {
				if (memo[n] < memo[i] + val[n]) {
					//cout << "memo[" << n << "] �� memo[" << i << "] + val[" << n << "] �� ������Ʈ�Ǿ� " << memo[i] + val[n] << " �� �Ǿ����ϴ�." << endl;
					memo[n] = memo[i] + val[n];
					if (maxmemo < memo[n])
						maxmemo = memo[n];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	memo[0] = val[0];
	DP_BU(0);
	cout << maxmemo;
	return 0;
}