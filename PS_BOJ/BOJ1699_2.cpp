#include <iostream>
#include <cmath>
#define MAX (int)1e5+1
using namespace std;

int mindepth = MAX;
int kazu[MAX];//�������� �� �� �������� �޸�뵵
int sougo;//���� �� ���� �������� ������ ��Ÿ��������
int n;

void DFS(int sum, int depth, int cursor) {
	if (sum >= n) {
		if (sum == n) {
			cout << depth << endl;
			if (mindepth > depth)
				mindepth = depth;
		}
		return;
	}
	else {
		for (int i = cursor; i > 0; i--) {
			int add = (int)pow(i, 2);
			kazu[i]++; sougo += add;
			DFS(sum + add, depth + 1, i);
			kazu[i]--; sougo -= add;
		}
	}
}

int main() {
	cin >> n;
	DFS(0, 0, (int)sqrt(n) + 1);
	cout << mindepth << endl;
	return 0;
}