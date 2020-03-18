#include <bits/stdc++.h>
using namespace std;

/*
소문자로만 주어진 n개의 단어가 주어진다. 주어진 암호문을 복호화하라.
후보단어는 16철자를 초과하지 않는다.
암호문은 공백포함 80자를 초과하지 않는다.

1. 중복해서 쓰이거나 안쓰이는 단어가 있을 수 있나?
2. 

2. 백트래킹으로 풀어보자 일단.
vector<string> Dict[17]; // word의 길이별로 vector에 저장.
a~z의 하나하나가 어디에 매칭되는지 일단 메모해뒀다가, 모순이 발생하면 빠꾸친다.

이거 트라이써도 먹힐 것 같다.
*/

int n;
vector<string> dict[17];
int dt[26];//decryptTable, 0번부터 a
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