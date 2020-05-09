#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
������Ʈ�� �����Ƿ� ����Ʈ������ ������ ���� �ǰڴ�
*/

int t;
int n;
int arr[8003];
int psum[8003];
int cnt;

int query(int l, int r, int i) {//i�ε����� ���� l�ε��� �̻� r �ε��� ���� ������ ���� ������ ��, 
	int seg = psum[r] - psum[l];
	if (seg == arr[i]) return 0;
	else if (seg > arr[i]) return 1;
	else return -1;
}

bool aq(int i) {//i�ε����� ���� ����������. ����� ���Ҹ� Ʈ��, �ƴϸ� ����
	for (int l = 0; l <= n - 1; l++) {
		for (int r = l + 2; r <= n; r++) {
			if (query(l, r, i) == 0) {
				//cout << l << " " << r << "�� lr������ ���� �����ϹǷ�," << i << " �ε����� Ư������" << endl;
				return true;
			}
			else if (query(l, r, i) == 1) break;
			else continue;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(psum, 0, sizeof(psum)); cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (i != 0) psum[i] = psum[i - 1] + arr[i];
			else psum[i] = arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (aq(i)) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}