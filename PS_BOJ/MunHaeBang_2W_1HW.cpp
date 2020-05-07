#include <bits/stdc++.h>
using namespace std;

int n;
//vector<string> inputs;
vector<char> vct;

bool IsOk(char c) {
	if (c == ')' && vct.back() != '(')
		return false;
	else if (c == '}' && vct.back() != '{')
		return false;
	else if (c == ']' && vct.back() != '[')
		return false;
	else
		return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while(n--) {
		vct.clear();
		string tmp;
		cin >> tmp;
		bool no = false;
		for (char c : tmp) {
			if (c == '(' || c == '{' || c == '[')
				vct.push_back(c);
			else if (!vct.empty() && IsOk(c))
				vct.pop_back();
			else {
				no = true;
				break;
			}
		}
		if (!no && vct.empty())
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}

	return 0;
}