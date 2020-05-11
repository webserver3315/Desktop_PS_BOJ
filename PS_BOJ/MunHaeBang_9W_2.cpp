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

bool isKun(const string& a, const string& b) {//0 �Ǵ� 1 �ִ������Ÿ��� true, �ƴϸ� false
	int cnt = 0;//1�������� ����
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
		}//���� 1���� �̻��̸� ��������
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

int ans = 0;
void dfs(int cur, int d) {
	ans = max(ans, d);
	for (int next : adj[cur])
		dfs(next, d + 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		vct.push_back(tmp);
		for (int j = 0; j < i; j++) {//���Ḯ��Ʈ ����
			if (isKun(vct[i], vct[j])) {
				adj[j].push_back(i); indegree[i]++;
				//cout << " ���� �Լ�: " << vct[j] << " �� " << vct[i] << " �� �����Ÿ� 0 �Ǵ� 1" << endl;
			}
			/*if (connect(vct[i], vct[j])) {
				adj[j].push_back(i);
				cout << " ���� �Լ�: " << vct[j] << " �� " << vct[i] << " �� �����Ÿ� 0 �Ǵ� 1" << endl;
			}*/
		}
	}

	for (int i = 0; i < n; i++) {
		if (indegree[i]) continue;
		else {
			dfs(i, 1);
		}
	}
	cout << ans << endl;

	return 0;
}