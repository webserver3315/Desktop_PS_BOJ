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
int table[26];//decryptTable, 0번부터 a
vector<string> ct;//cypher text
string cts;//cypher text string
vector<string> ptvct;//plain text

char dcc(char c) {//decrypt char
	return table[c - 'a'] + 'a';
}

bool dfs(int cur) {//backtracking
	if (cur == ct.size()) {
		for (string str : ptvct) {
			cout << str << ' ';
		}
		cout << endl;
		return true;
	}
	int len = ct[cur].length();
	for (const string& pt : dict[len]) {//ct[cur]과 pt가 현재 테이블에 따랐을 때 모순없는지를 체크해야한다. 테이블을 덮어쓰는 사태가 발생하면 터트려야한다.
		vector<int> tableupdatedhistory;
		bool dameda = false;
		for (int i = 0; i < pt.size(); i++) {
			char c = ct[cur][i];
			if (table[c - 'a'] == -1) {//이거 빠꾸칠때 원상복귀하는거 구현 어케하냐. 일단 tableupdated벡터 씀
				table[c - 'a'] = pt[i] - 'a';
				tableupdatedhistory.push_back(c - 'a');
			}
			else {
				if (dcc(c) != pt[i]) {//매치안되면 다음 추정평문후보 꺼내자
					for (int i : tableupdatedhistory) {
						table[i] = -1;
					}
					tableupdatedhistory.clear();
					dameda = true;
					break;
				}
			}
		}
		if (dameda)//2중for문 탈출용
			continue;
		else
			ptvct.push_back(pt);

		if (dfs(cur + 1))
			return true;
		else
			ptvct.pop_back();
	}
	return false;
}

void tokenizer(const string& str) {
	string tmp;
	for (char c : str) {
		if (c == ' ') {
			ct.push_back(tmp);
			tmp.clear();
			continue;
		}
		tmp.push_back(c);
	}
	ct.push_back(tmp);
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
	while (getline(cin, cts)) {
		if (cts.empty())
			continue;
		memset(table, -1, sizeof(table));
		ct.clear(); ptvct.clear();
		tokenizer(cts);
		if (!dfs(0)) {
			for (string str : ct) {
				for (int i = 0; i < str.length(); i++) {
					cout << '*';
				}
				cout << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}