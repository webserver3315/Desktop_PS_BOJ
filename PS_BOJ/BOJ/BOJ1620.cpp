#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cctype>
#define endl '\n'
using namespace std;

int n, m;
map<char*, int> dict;
char dict2[100000][20];

struct cmp_str
{
	bool operator()(char const* a, char const* b) const
	{
		return std::strcmp(a, b) < 0;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	//char name[22];
	for (int i = 1; i <= n; i++) {
		cin >> dict2[i];
		dict.insert(make_pair(dict2[i], i));
	}
	
	for (int i = 0; i < m; i++) {
		char tmp[22];
		cin >> tmp;
		if (tmp[0]<'0' || tmp[0]>'9') {//이름이면
			cout << dict.find(tmp)->second << endl;
		}
		else {
			int tmptmp = atoi(tmp);
			cout << dict.find(tmptmp)->first << endl;
		}
	}

	return 0;
}