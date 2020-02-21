#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int t;
int x, y;
int n;
int accel;
int ans;

/*음수번 갈 일이 없다고 일단 생각한다.
2e31이면 1000e3이고, 1e9인데 이거 10억인데
생각해보니 dp 없으면 연산량부족으로 애초에 안된다.
*/

signed main() {
	cin >> t;
	while (t--) {
		cin >> x >> y;
		accel = 0; ans = 0;
		n = y - x;
		while ((accel + 1) * (accel + 2) < n) {
			accel++;
		}
		ans = 2 * accel;
		if (accel * (accel + 1) != n) {
			int plus = ceil(((n - accel * (accel + 1)) / (float)(accel + 1)));
			ans += plus;
			if (plus == 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}