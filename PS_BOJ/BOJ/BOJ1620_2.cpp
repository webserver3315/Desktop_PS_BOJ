#include <iostream>
#include <string>
#include <map>
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

int N, M;
map<string, int> NaSu;//이름->수
map<int, string> SuNa;//수->이름

bool isDigit(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i]>'9')
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		NaSu.insert(mp(str, i));
		SuNa.insert(mp(i, str));
	}
	for (int i = 0; i < M; i++) {
		string order;
		cin >> order;
		if (isDigit(order)) {
			cout << SuNa.find(stoi(order))->second << endl;
		}
		else {
			cout << NaSu.find(order)->second << endl;
		}
	}

	return 0;
}