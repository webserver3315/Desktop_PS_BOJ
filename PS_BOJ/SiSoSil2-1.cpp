#include <bits/stdc++.h>
using namespace std;

/*
비둘기집원리에 따라, 간극의 개수는 n-1개고 간극의 범위가 1~n-1이므로, 절대 간극너비가 중복되어서는 안된다.
n은 3000 이하.
뇌비우고 초 naive하게 풀자면,
인접한 차이를 다 기록한 뒤
sort때려서 1부터 n-1까지 빠짐없이 있는지만 확인하면 문제없다.
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