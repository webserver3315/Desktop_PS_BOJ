#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
vector<string> vct;
vector<int> adj[25002];

bool isKun(string a, string b) {
	int cnt = 0;//1번까지는 ㄱㄴ
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				cnt++;
			}
		}

		if (cnt < 2) return true;
		else return false;
	}
	else {
		int al=a.length(); int bl=b.length();
		if (abs(al - bl) > 1) {
			return false;
		}
		if (a.length() < b.length()) {
			string tmp = b; b = a; a = tmp;
		}
		int i, j;
		for (i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				break;
			}
			
		}
		for (j = 0; j <b.length; j++) {
			if (a[(int)a.length() - 1 - j] != b[(int)b.length() - 1 - j])
				break;
		}
		if (j > (int)a.length() - 1 - j) {
			return true;
		}
		else
			return false;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		vct.push_back(tmp);
		for (int j = 0; j < i; j++) {
			if (isKun(vct[i], vct[j])) {
				adj[j].push_back(i);
			}
		}



	}

	return 0;
}