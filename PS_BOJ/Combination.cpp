/*
nCr
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#define endl '\n'
using namespace std;

int N, M;
vector<int> Stack;

/*������ ���, ������ �ٸ��� visited�� �ʿ���� ���, dfs�� ���� ���� �ϳ� �� �þ��.
������ �ϸ� �ǹǷ�, kensakuchu ���ڸ� �߰��� ��������.

kensakuchu ���ڰ� �������ν� ���ڰ� �� 2���� �Ǿ�����, ���������� �Ѵٸ� IsComplete�� ���� �� ���� ���ڸ� ��� ����ϴ� ������ ��������� �Ѵ�.
���, ����ο����� visited üũ�� �翬�� ������ �ʿ����.*/
void Combination(int Start, int Selected) {
	if (Selected == M) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = Start; i <= N; i++) {/*kensakuchu���� �����ϴ°ɷ� �ؾ��Ѵ�. �ո����� �����ϵ��� �����ϱ�.*/
		Stack.push_back(i);
		Combination(i + 1, Selected + 1);/*�� �Ǽ��ߴ�, Start�� �ƴ϶� i�� ���ڷ� �����;� �Ѵ�!!!!!!!!!!*/
		Stack.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	Combination(1, 0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}