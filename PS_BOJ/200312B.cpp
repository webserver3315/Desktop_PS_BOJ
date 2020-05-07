#include <iostream>
#include <cstring>
#include <vector>
#define endl '\n'
using namespace std;

int t, n;
int visited[5001];
vector<int> vct;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		int tmp;
		memset(visited, 0, sizeof(visited));
		vct.clear();
		bool yes = false;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			vct.push_back(tmp);
			if (visited[tmp] == 0) {
				visited[tmp]++;
			}
			else if (visited[tmp] == 1) {
				visited[tmp]++;
				if (vct[i - 1] != vct[i])
					yes = true;
			}
			else if (visited[tmp] == 2) {
				visited[tmp]++;
				yes = true;
			}
			else {
				cerr << "ERROR" << endl;
			}
		}
		if (yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl; 
	}

	return 0;
}
