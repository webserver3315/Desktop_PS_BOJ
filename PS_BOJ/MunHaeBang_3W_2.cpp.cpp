#include <bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;



int main(){

	int n;
	string str;
	while (cin >> n >> str) {
		map<string, int> dict;
		for (int i = 0; i <= str.length() - n; i++) {
			string sub = str.substr(i, n);
			map<string, int>::iterator iter;
			iter = dict.find(sub);
			if (iter == dict.end()) {
				dict.insert(mp(sub, 1));
			}
			else {
				dict[sub]++;
			}
		}
		vector<pair<int, string>> vct;
		for (auto a : dict) {
			vct.push_back(mp(a.ss, a.ff));
		}
		sort(vct.begin(), vct.end());
		int maxval = vct.back().ff;
		int cnt = 0;
		for (int i = vct.size() - 1; i >= 0 && cnt < 2; i--) {
			if (maxval == vct[i].ff)
				cnt++;
		}
		if (cnt >= 2)
			cout << '*' << endl;
		else
			cout << vct.back().ss << endl;
	}
	return 0;
}