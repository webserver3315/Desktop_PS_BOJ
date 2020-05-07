#include <bits/stdc++.h>
using namespace std;

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

	string line;
	while (getline(cin, line)) {
		if (line.empty())
			continue;
		for (char c : line) {
			if (c == ' ')
				cout << "___";
			cout << ctom(c) << ' ';
		}
		cout << endl;
	}


	return 0;
}