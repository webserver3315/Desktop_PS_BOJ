#include <bits/stdc++.h>
using namespace std;

/*
�ҹ��ڷθ� �־��� n���� �ܾ �־�����. �־��� ��ȣ���� ��ȣȭ�϶�.
�ĺ��ܾ�� 16ö�ڸ� �ʰ����� �ʴ´�.
��ȣ���� �������� 80�ڸ� �ʰ����� �ʴ´�.

1. �ߺ��ؼ� ���̰ų� �Ⱦ��̴� �ܾ ���� �� �ֳ�?
2. 

2. ��Ʈ��ŷ���� Ǯ��� �ϴ�.
vector<string> Dict[17]; // word�� ���̺��� vector�� ����.
a~z�� �ϳ��ϳ��� ��� ��Ī�Ǵ��� �ϴ� �޸��ص״ٰ�, ����� �߻��ϸ� ����ģ��.

�̰� Ʈ���̽ᵵ ���� �� ����.
*/

int n;
vector<string> dict[17];
int dt[26];//decryptTable, 0������ a
vector<string> pt;//plaintext

char dcc(char c) {//decrypt char
	return dt[c - 'a'] + 'a';
}

string dcs(string s) {//decrypt string
	for (int i = 0; i < s.length(); i++) {
		s[i] = dcc(s[i]);
	}
	return s;
}

void bt(int cur) {//backtracking
	if (cur == pt.size())
		return;
	int len = pt[cur].length();
	for (string kouhou : dict[len]) {

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dict[tmp.size()].push_back(tmp);
	}
	for (cin >> tmp) {

	}

	return 0;
}