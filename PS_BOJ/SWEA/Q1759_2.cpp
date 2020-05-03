/*
암호 만들기
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int l, c;/*c:후보글자 개수, l: 원하는 글자수*/
int consonant, vowel;
string str;
string strbuf;

int PrintAllVisited() {
	cout << strbuf << endl;
	return 0;
}

bool IsVowel(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

int DFS(int depth, int visited, int consonant, int vowel) {
	if (visited == l && consonant >= 2 && vowel >= 1) {
		//cout << "DFS " << depth << " " << visited << endl;
		PrintAllVisited();
		return 0;
	}
	else if (depth != c) {
		strbuf += str[depth];
		if (IsVowel(str[depth])) {
			vowel++;
			DFS(depth + 1, visited + 1, consonant, vowel);
			strbuf.pop_back();
			vowel--;
			DFS(depth + 1, visited, consonant, vowel);
		}
		else {
			consonant++;
			DFS(depth + 1, visited + 1, consonant, vowel);
			strbuf.pop_back();
			consonant--;
			DFS(depth + 1, visited, consonant, vowel);
		}
		return 0;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char tmpstr[15];
		cin >> tmpstr;/*string str 선언 후 그냥 cin>>str 하면 공백 이전까지만 입력받아져 str에 저장된다*/
		str += tmpstr;
	}
	sort(str.begin(), str.end());

	//cout << " str체크용 " << str << '\n' << endl;

	DFS(0, 0, 0, 0);
	return 0;
}