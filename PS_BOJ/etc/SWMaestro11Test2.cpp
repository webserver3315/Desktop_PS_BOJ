#include <bits/stdc++.h>
#define endl '\n'
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

int N, K;
vector<int> vct;
//multimap<int,int> minIdx;//�ּҰ����� ��ġ_key=��,val=��ġ
int idx1;
int minval = INT32_MAX;
int L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
		if (tmp == 1)
			idx1 = i;
	}
	L = idx1;
	R = N - idx1 - 1;
	cnt += ceil(L / (K - 1));
	cout << "�¿��� " << cnt << " ����" << endl;
	L %= (K - 1);
	R -= (K - 1 - L);
	cout << "�찡 " << R << " �� ��" << endl;
	cout << "�쿡�� " << ceil(R / (K - 1)) << " ����" << endl;
	cnt += ceil(R / (K - 1));
	cout << cnt << endl;

	return 0;
}