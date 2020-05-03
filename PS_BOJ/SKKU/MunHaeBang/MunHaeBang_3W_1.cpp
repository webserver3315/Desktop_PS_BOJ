#include <bits/stdc++.h>
using namespace std;

int alpha[27];

int main() {

	string str;
	while (cin>>str) {
		memset(alpha, 0, sizeof(alpha));
		for (char c : str) {
			if (c >= 'a' && c <= 'z') {
				alpha[c - 'a']++;
			}
			else if (c >= 'A' && c <= 'Z') {
				alpha[c - 'A']++;
			}
			else
				cerr << "ERROR" << endl;
		}
		int maxidx = 0;
		for (int i = 0; i < 27; i++) {
			if (alpha[maxidx] < alpha[i])
				maxidx = i;
		}
		int cnt = 0;
		for (int i = 0; i < 27; i++) {
			if (alpha[i] == alpha[maxidx])
				cnt++;
		}
		if (cnt >= 2)
			cout << '*' << endl;
		else
			cout << char('A' + maxidx) << endl;
	}

	return 0;
}//범위초과오류 안나는지 확인