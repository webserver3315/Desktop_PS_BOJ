/*
2*N Ÿ�ϸ�
*/

#include <iostream>

using namespace std;

/*2*n ���簢���� 2*1, 2*2 �簢������ ä��� ����� ���� ���϶�.
�������簢���� ���α��̰� �־�����

*/

int N;
int memo[1005] = { 0,1,3,5, };
bool visit[1005] = { false, true, true, true, };
#define DIV 10007

/*�����κ������� ������ ������. ��, DP�� Ǯ �� �ִ�. ��ȭ���� ã�⸸ �Ѵٸ�.
���� N�� �� ����� ���� fN�̶�� �� ��
f(n)=f(n-2)*2 + f(n-1) �� �����ϴٰ� �����ȴ�.
f(1)=1, f(2)=3, f(3)=5, f(4) = 
*/

int DP(int n) {
	if (visit[n]) {
		return memo[n];
	}
	visit[n] = true;
	memo[n] = (DP(n - 1) + DP(n - 2) * 2) % DIV;//10007�� ������ ��ũ�� ������ ��
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cout << DP(N) << endl;
	return 0;
}