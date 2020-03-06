#include <iostream>
#include <string>
#define MAX 10
#define endl '\n'
using namespace std;

int R, C;
string fish[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		cin >> fish[r];
	}

	for (int r = 0; r < R; r++) {
		for (int c = fish[r].length() - 1; c >= 0; c--) {
			cout << fish[r][c];
		}
		cout << endl;
	}

	return 0;
}