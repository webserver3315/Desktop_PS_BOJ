#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


/*
N이 1000 이하.
모든 선택의 경우의 수를 따지면 2의 1000승, 즉 에바.
정렬?
1 1 2 3 6 7 30
1 2 4 7 13 20 50
여태까지의 합보다 지금 넣을 값이 2 이상 크다면 ㅈㅈ.

자신보다 작은 수를 다 더해보자.
1
2
3

"""N번째 숫자까지 사용할 때 K까지 가능했다.""" 라는 것을 메모함.
갑자기 2칸 이상 점프하면 ㅈㅈ.
*/

int n;
set<int> iset;
vector<int> vct;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end());
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (sum + 1 < vct[i])
			break;
		sum+=vct[i];
	}
	cout << sum + 1 << endl;
	return 0;
}