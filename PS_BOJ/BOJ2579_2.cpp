/*
2020.03.04
DP ž�ٿ� �󱼸��㹮�� ����
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#define MAX 305
using namespace std;

int N;
int memo[MAX][2];//0:������ܵ� ����� ��, 1: ������� �ȹ���� ��
int memo2[MAX];
int val[MAX];

//int DP(int n, bool hasStep) {//������, ��������� ��Ҵ�������
//	if (n < 1 || (n == 1) && hasStep)
//		return 0;
//	int& ret = memo[n][hasStep];
//	if (ret != -1)
//		return ret;
//	ret = max(DP(n - 3, true), DP(n - 3, false));
//	if (hasStep)
//		ret += DP(n - 1, false);
//	else
//		ret += DP(n - 2, true);
//	ret += val[n];
//	return ret;
//}

int DP(int n, bool hasStep) {//������, ��������� ��Ҵ�������
	if (n < 1 || (n == 1) && hasStep)
		return 0;
	int& ret = memo[n][hasStep];
	if (ret != -1)
		return ret;
	if (hasStep)
		ret = DP(n - 1, false) + val[n];
	else
		ret = DP(n - 2, true) + val[n];
	return ret;
}

int DP2(int n) {
	if (n < 1)
		return 0;
	int& ret = memo2[n];
	if (ret != -1)
		return ret;
	ret = val[n];
	ret += max(DP2(n - 3) + val[n - 1], DP2(n - 2));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
	}
	memset(memo, -1, sizeof(memo));
	//memset(memo2, -1, sizeof(memo2));
	//cout << DP2(N) << endl;
	cout << max(DP(N, true), DP(N, false)) << endl;
	return 0;
}