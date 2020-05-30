#include <bits/stdc++.h>
#define int long long
#define pii pair<long long, long long>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

int N;
int t;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> t;
		int Aphase = 1;
		int Bphase = 1;
		while (Aphase * Aphase < t) {
			Aphase++;
		}
		while ((Bphase * (Bphase + 1)) / 2 < t) {
			Bphase++;
		}
		//t==1�� �� �������� üũ�� ��
		int At = t - (Aphase-1) * (Aphase-1);//������� �� ��°������ ���. ù ������ 1.
		int Bt = t - (Bphase * (Bphase - 1)) / 2;
		int Ax, Ay, Bx, By;
		if (Aphase % 2 == 0) {//¦��
			Ax = 1; Ay = Aphase;
			while (--At) {
				if (Ax < Aphase) {
					Ax++;
				}
				else {
					Ay--;
				}
			}
		}
		else {//¦��
			Ax = Aphase; Ay = 1;
			while (--At) {
				if (Ay < Aphase) {
					Ay++;
				}
				else {
					Ax--;
				}
			}
		}

		if (Bphase % 2 == 0) {
			By = 1; Bx = Bphase + 1 - By;
			while (--Bt) {
				By++; Bx--;
			}
		}
		else {
			Bx = 1; By = Bphase + 1 - Bx;
			while (--Bt) {
				Bx++; By--;
			}
		}
		cout << Ax << " " << Ay << " " << Bx << " " << By << " " << endl;
	}


	return 0;
}