#include <iostream>
#include <cmath>
#define MAX (int)1e5+1
using namespace std;

int memo[MAX];
int n;

/*
DFS�� n!�� ���������ϴ� �� �ܿ��� �ƹ� ����� ���ٰ� ������.
�׷���, ������ �����ش� �ش� �� ��ü�� �������̰ų�, �� ���� ��� ��쿡��
�ݵ�� ���� �����ͷκ��� ���� ������ �� ������ �ڸ��ϹǷ�
DP�� Ǯ �� �ִٴ� ����� Ǯ�̸� ���� ���޾Ҵ�.

DP�� �߻�����: "���� �����ͷκ��� ���� �����Ͱ� ���Ⱑ���Ѱ�? ��, ���������Ͱ� ������ ���� ���ϴµ� �����ִ°�?"

����:https://wootool.tistory.com/102
*/

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (memo[i] > memo[i - j * j] + 1 || memo[i] == 0) {
				memo[i] = memo[i - j * j] + 1;
			}
		}
	}

	cout << memo[n] << endl;

	return 0;
}