#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
#define pii pair<int, int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;

int N;
vector<pii> vct;
int memo[1001]; //n���� ���ʰ����� �ִ빫�Ը� �޸�. 0������ ����
int done[1001];
int kai = 0;
vector<pii> tower;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(done, -1, sizeof(done));
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vct.push_back(mp(b - a, a));//��¥���ʷ�, ���� ������ �־���
	}
	sort(vct.begin(), vct.end(),greater<pii>());

	int cur, pushed, updated;
	for (; kai < N; kai++) {
		updated = false;
		for (cur = 0; cur < N; cur++) {
			if (done[cur] != -1) continue;
			if (kai == 0) {
				int hikaku = vct[cur].ff;
				if (memo[kai] < hikaku) {
					memo[kai] = hikaku;
					pushed = cur;
					updated = true;
				}
			}
			else {
				int hikaku = min(memo[kai - 1] - vct[cur].ss, vct[cur].ff);
				if (memo[kai] < hikaku) {
					memo[kai] = hikaku;
					pushed = cur;
					updated = true;
				}
			}
		}
		if (!updated) break;
		tower.push_back(vct[pushed]);
		done[pushed] = kai;
	}
	
	cout << tower.size() << endl;

	return 0;
}