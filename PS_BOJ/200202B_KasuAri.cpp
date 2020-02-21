#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>

#define X first
#define Y second
#define ll long long
#define MOD 1000000007
#define MAX 303030
using namespace std;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int t, n;
int a[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		int left, right;
		left = 0; right = n - 1;
		for (int i = 0; i < n; i++) {
			if (i <= a[i]) left = i;
			else break;
		}
		for (int i = n - 1; i >= 0; i--) {
			if ((n - 1 - i) <= a[i]) right = i;
			else break;
		}
		if (left >= right) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}