#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


/*
N�� 1000 ����.
��� ������ ����� ���� ������ 2�� 1000��, �� ����.
����?
1 1 2 3 6 7 30
1 2 4 7 13 20 50
���±����� �պ��� ���� ���� ���� 2 �̻� ũ�ٸ� ����.

�ڽź��� ���� ���� �� ���غ���.
1
2
3

"""N��° ���ڱ��� ����� �� K���� �����ߴ�.""" ��� ���� �޸���.
���ڱ� 2ĭ �̻� �����ϸ� ����.
*/

int n;
set<int> iset;
vector<int> vct;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end());
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (sum + 1 < vct[i])
			break;
		sum+=vct[i];
	}
	cout << sum + 1 << endl;
	return 0;
}