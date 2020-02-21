/*
N�� M(1)


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
using namespace std;


int N, M;
array<bool, 9> visit;
vector<int> GlobalVct;
queue<int> KotaeQue;
/*���� M�� �ߺ����� N�߿��� �� ������ ��� ���϶�.
�ƾƾ� ���� ������ �ƴϳ�.
1~8�����ۿ� ������ visit �迭 ��߰ڱ���
������ �ƴϴϱ� start �Ű������� �ʿ��ϴ�.
4312�� �������� ȣ��� start�Ű������� �ڵ����� �ذ����� ���̴�.

���� ����� M �ʰ��� �ٷ� ��������ϰ� ����0 ������. ������� kotaeque�� size�Ű������� ����ȭ�ȴ�.

*/

int DFS(array<bool,9>& Localvisit, int depth, int Vctsize) {
	if (depth >= N) {
		return 0;
	}
	else if (Vctsize >= M ) {
		for (int tmp : GlobalVct) {
			cout << tmp << ' ';
		}
		cout << '\n';
		return 0;
	}
	
	for (int i = 1; i <= N; i++) {
		if (Localvisit[i] == false) {
			Localvisit[i] = true;
			GlobalVct.push_back(i);
			DFS(Localvisit, depth + 1, Vctsize + 1);
			Localvisit[i] = false;
			GlobalVct.pop_back();
			DFS(Localvisit, depth + 1, Vctsize);
		}
	}
}


/*
������ ������ N���� ū ���� �����ϰų�, M�� ���� á�� ��.
�ٵ� M�� ���� á������ �׳� ������ �н��ع����°� ���� �ʳ�? �������� ���� ���� ��� ���ص� �ȴ�.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	DFS(visit, 0, 0);

	return 0;
}