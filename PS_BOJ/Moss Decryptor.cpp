#include <bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;

map<string, char> dict;

string ctom(char c) {
	switch (c) {
	case 'A':	return "*-";
	case 'B':	return "-***";
	case 'C':	return "-*-*";
	case 'D':	return "-**";
	case 'E':	return"*";
	case 'F':	return"**-*";
	case 'G':	return"--*";
	case 'H':	return"****";
	case 'I':	return"**";
	case 'J':	return"*---";
	case 'K':	return"-*-";
	case 'L':	return"*-**";
	case 'M':	return"--";
	case 'N':	return"-*";
	case 'O':	return"---";
	case 'P':	return"*--*";
	case 'Q':	return"--*-";
	case 'R':	return"*-*";
	case 'S':	return"***";
	case 'T':	return"-";
	case 'U':	return"**-";
	case 'V':	return"***-";
	case 'W':	return"*--";
	case 'X':	return"-**-";
	case 'Y':	return"-*--";
	case 'Z':	return"--**";
	case '0':	return"-----";
	case '1':	return"*----";
	case '2':	return"**---";
	case '3':	return"***--";
	case '4':	return"****-";
	case '5':	return"*****";
	case '6':	return"-****";
	case '7':	return"--***";
	case '8':	return"---**";
	case '9':	return"----*";
	case '-': return "-****-";
	case '.': return "*-*-*-";
	case ',': return "--**--";
	case '(': return "-*--*";
	case ')': return "-*--*-";
	case '/': return "-**-*";
	case '?': return "**--**";
	default:	cerr << "Encrypt Failed" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (char c = 'A'; c <= 'Z'; c++) {
		string code = ctom(c);
		dict.insert(make_pair(code, c));
	}
	for (char c = '0'; c <= '9'; c++) {
		string code = ctom(c);
		dict.insert(make_pair(code, c));
	}
	dict.insert(mp("-****-", '-'));
	dict.insert(mp("*-*-*-", '.'));
	dict.insert(mp("--**--", ','));
	dict.insert(mp("-*--*", '('));
	dict.insert(mp("-*--*-", ')'));
	dict.insert(mp("-**-*", '/'));
	dict.insert(mp("**--**", '?'));
	dict.insert(mp("___", ' '));

	string code;
	while (cin>>code) {
		if (code.empty()) {
			cout << endl;
			continue;
		}
		cout << dict.find(code)->second;
	}


	return 0;
}