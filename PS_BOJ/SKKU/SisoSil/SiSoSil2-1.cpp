#include <bits/stdc++.h>
using namespace std;

/*
��ѱ��������� ����, ������ ������ n-1���� ������ ������ 1~n-1�̹Ƿ�, ���� ���سʺ� �ߺ��Ǿ�� �ȵȴ�.
n�� 3000 ����.
������ �� naive�ϰ� Ǯ�ڸ�,
������ ���̸� �� ����� ��
sort������ 1���� n-1���� �������� �ִ����� Ȯ���ϸ� ��������.
*/

int n;
vector<int> vct;
vector<int> diff;

bool isJolly() {
	for (int i = 0; i < diff.size(); i++) {
		if (diff[i] != i + 1)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n) {
		vct.clear(); diff.clear();
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			vct.push_back(tmp);
		}
		for (int i = 0; i < vct.size() - 1; i++) {
			int dif = abs(vct[i] - vct[i + 1]);
			diff.push_back(dif);
		}
		sort(diff.begin(), diff.end());
		if (isJolly())
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}