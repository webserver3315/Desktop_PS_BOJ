#include <bits/stdc++.h>
#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
int t, n, k;
int x;
vector<int> arr;
map<int, int> need;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		arr.clear();
		need.clear();
		x = 0;
		int cnt = 0;
		bool calc = false;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
			int keys = (((arr[i] / k) + 1) * k - arr[i]);
			if (keys != k) {
				calc = true;
			}
			if (keys == k) continue;
			if (need.count(keys) == 0) {
				// cout << keys << "����" << endl;
				need.insert(mp(keys, 1));
			}
			else {
				need[keys]++;
				// cout << need[keys] << endl;
			}
		}
		// cout << "���� �� need size �� " << need.size() << endl;
		//Greedy�ϰ� �ص� �ȴ�.
		while (!need.empty()) {
			cout << "need size �� " << need.size() << endl;
			for (auto a : need) {
				cout << a.ff << " " << a.ss << "   ";
			}
			cout << endl;
			if (!calc) {  //������ need�� 0�̸�, ���� �̹� �������ٴ� ��.
				break;
			}
			else {
				x = 0;
				for (auto a : need) {
					int key = a.ff;
					int val = a.ss;
					cout << "cnt+=" << key << "-" << x << endl;
					cnt += key - x;
					x = key;
					cout << "x updated! " << x << endl;
					if (need[key] > 0) {
						need[key]--;
						if (need[key] == 0) {
							need.erase(key);
							if (need.empty())
								break;
						}
					}
				}
				// cout << "x�� cnt�� " << x << " " << cnt << endl;
			}
			cnt += k - x;
			cout << "cnt+=" << k << "-" << x << endl;
		}
		if (calc) {
			cout << cnt << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}