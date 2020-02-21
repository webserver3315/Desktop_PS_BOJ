/*
�κм����� ��

-������ Ǯ� ������. ������ C�ε� ������ Ǯ����. 30���Ƴ���
>>>12�аɷȴ�.
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

/*�κм����� ����: ���� ���ӵ� �ʿ�� ����. �׳� �� �����⸸ �ϸ� �ȴ�. ���Ҵ� �ߺ����� �־��� �� ������, �����ķ� �־�����.
������ 20���� �޴� �ɷ� �ϴ� �Ǿ��ִ�. ������ ������ 10���� ���� �����Ƿ� int������ �ʰ����� �ʴ´�.
��͸� �̿��� dfs�� 0~n, 1~n, 2~n �̷� ������ �����س����� �ݹ� �����ϴ�. ��, ��Ž_��Ʈ��ŷ�̴�.

dfs�� ���ؼ��� �Ű������� depth, sum�� ������ �ʿ䰡 �ִ�. start�� �׻� �������θ� �˻��� ���̹Ƿ� ������ �ʿ䰡 ����.
*/

int N, S, cnt;
vector<int> GlobalVct;

int BackTracking(int depth, int sum) {
	if (depth >= N) {
		return 0;
	}
	if (sum + GlobalVct[depth] == S) {
		cnt++;
	}
	BackTracking(depth + 1, sum + GlobalVct[depth]);
	BackTracking(depth + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		GlobalVct.push_back(tmp);
	}
	BackTracking(0, 0);
	cout << cnt << endl;
	return 0;
}