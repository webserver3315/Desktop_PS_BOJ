#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int t;
int x, y;
int n;
int accel;
int ans;

/*������ �� ���� ���ٰ� �ϴ� �����Ѵ�.
2e31�̸� 1000e3�̰�, 1e9�ε� �̰� 10���ε�
�����غ��� dp ������ ���귮�������� ���ʿ� �ȵȴ�.
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