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
int table[26];//decryptTable, 0������ a
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
	for (const string& pt : dict[len]) {//ct[cur]�� pt�� ���� ���̺� ������ �� ����������� üũ�ؾ��Ѵ�. ���̺��� ����� ���°� �߻��ϸ� ��Ʈ�����Ѵ�.
		vector<int> tableupdatedhistory;
		bool dameda = false;
		for (int i = 0; i < pt.size(); i++) {
			char c = ct[cur][i];
			if (table[c - 'a'] == -1) {//�̰� ����ĥ�� ���󺹱��ϴ°� ���� �����ϳ�. �ϴ� tableupdated���� ��
				table[c - 'a'] = pt[i] - 'a';
				tableupdatedhistory.push_back(c - 'a');
			}
			else {
				if (dcc(c) != pt[i]) {//��ġ�ȵǸ� ���� �������ĺ� ������
					for (int i : tableupdatedhistory) {
						table[i] = -1;
					}
					tableupdatedhistory.clear();
					dameda = true;
					break;
				}
			}
		}
		if (dameda)//2��for�� Ż���
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