#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
vector<string> vct;
int indegree[25002];
vector<int> adj[25002];

//bool connect(const string& a, const string& b) {
bool connect(string a, string b) {
	if (a.size() > b.size()) swap(a, b);
	int asz = a.size(), bsz = b.size();
	if (bsz - asz > 1) return 0;

	int le = 0, ri = bsz - 1;
	while (le < asz && a[le] == b[le]) le++;
	if (asz == bsz) while (ri >= 0 && a[ri] == b[ri]) ri--;
	else while (ri - 1 >= 0 && a[ri - 1] == b[ri]) ri--;
	return le == ri;
}

bool isKun(const string& a, const string& b) {//0 또는 1 최단편집거리면 true, 아니면 false
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
		int al=a.length(); int bl=b.length();//alength, blength
		if (abs(al - bl) > 1) {
			return false;
		}//길이 1차이 이상이면 가망없음
		int l, ar, br;//left, aright, bright index
		for (l = 0; l < min(a.length(),b.length()); l++) {
			if (a[l] != b[l]) {
				break;
			}
		}
		for (ar = a.length() - 1, br = b.length() - 1; ar >= 0 && br >= 0; ar--, br--) {
			if (a[ar] != b[br]) {
				break;
			}
		}
		if (l == max(ar,br)) {
			return true;
		}
		else
			return false;
	}
}

int dfs(int cur, int d) {
	int maxjmp = 1;
	for (int next : adj[cur]) {
		int nowjmp = dfs(next, d + 1);
		if (maxjmp < nowjmp) maxjmp = nowjmp;
	}
	return maxjmp;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		vct.push_back(tmp);
		for (int j = 0; j < i; j++) {//연결리스트 제조
			if (isKun(vct[i], vct[j])) {
				adj[j].push_back(i); indegree[i]++;
				cout << " 내꺼 함수: " << vct[j] << " 와 " << vct[i] << " 는 편집거리 0 또는 1" << endl;
			}
			/*if (connect(vct[i], vct[j])) {
				adj[j].push_back(i);
				cout << " ㅈㄱ 함수: " << vct[j] << " 와 " << vct[i] << " 는 편집거리 0 또는 1" << endl;
			}*/
		}
		for (int i = 0; i < n; i++) {
			if (indegree[i]) continue;
			else {
				cout<<dfs
			}
		}


	}

	return 0;
}