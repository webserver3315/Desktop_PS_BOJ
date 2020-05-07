#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX (int)2e5+1
using namespace std;

/*
1���� n������ ���Ͱ� �ټ��ִ�.
i�� ���ʹ� hi�� ü���� ������.
���� a�� ���ݷ��� ������.
�ٸ� �÷��̾�(?)�� b�� ���ݷ��� ������.

���� ���� �� ���͸� �ٱ����Ѵ�.
ü���� 0 �Ǵ� ������ �Ǹ� ���ʹ� �״´�.

���� ���� ��Ÿĥ������ 1����Ʈ�� ��´�.
��밡 ���� ��Ÿġ�� ����Ʈ ����´�.
������ ���� ����, ������ �� ��°�� ����ȴ�.
�ʴ� �ִ� k����ŭ ������ ������ �ѹ���� �� �ִ�.

�ѹ��� �ִ��� �����ϰ� ���Ƽ� ���� �� �ִ� �ִ����ġ�� ���϶�.
*/

int t;
int n, a, b, k;
int MonHealth[MAX];

int floatdiv(int a, int b) {
	if (a % b == 0)
		return a / b;
	if (a % b != 0)
		return (a / b) + 1;
}

int main() {
	//cin >> t;
	t = 1;
	while (t--) {
		cin >> n >> a >> b >> k;
		int cnt = 0;
		vector<int> nokoriHP;
		for (int i = 0; i < n; i++) {
			cin >> MonHealth[i];
			MonHealth[i] %= (a + b);
			if (MonHealth[i] == 0)
				MonHealth[i] = a + b;
			if (MonHealth[i] <= a) {
				cnt++;
			}
			else {
				nokoriHP.push_back(MonHealth[i]);
			}
		}
		sort(nokoriHP.begin(), nokoriHP.end());
		for (int i = 0; i < nokoriHP.size(); i++) {
			int nowMon = nokoriHP[i] - a;
			if (k >= floatdiv(nowMon , a)) {//�ѹ潺ų�� �����ִٸ�
				k -= floatdiv(nowMon , a);
				cnt++;
			}
			else
				break;
		}
		cout << cnt << endl;
	}
	return 0;
}