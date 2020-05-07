/*
�޸���
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

/*
���׸�Ʈ Ʈ���� �� ���Դ°�?
���� ����� �ٲ�� �迭���� �̿��� �׵��� ������ �ʿ䰡 ���� ��, �չ迭�ε� ����ȭ�� �Ұ����� ��츦 ������ �˻��ϱ� �����̴�.
*/

/*
���� ���� 5e5 ����. ��ġ�� �Ƿ� ����.
*/

/*
�ƴ�, �̰� �׳� ����������� sort�� ��, ���� ��ġ�� �������� �� ��ġ �� min�� ����ϸ� �ȵǳ�?
�ȵȴ�. ���� �Ƿ��ڰ� �ڽ��� ��ġ�� �ʾҴٴ� ������ �ʿ��ϴ�.
�׷��ٸ�, �ڽź��� 1������� ���ؼ��� ������ �Ǵ� �� �ƴѰ�?
�׷���, �׷��ٰ� �ϸ� ������ ������ ���� ���� sort�� �������ϴµ�, log5e5�� 5e5�� �ݺ��ϰ� �ǹǷ� 30e5�� �ȴ�. 3e6�̹Ƿ� 1�ʸ� �������ϱ� �ѵ�...
sort ������, �ڱ� ����ִ��� ã��, �װ� �ݺ�.
logN * logN(����) * N = 180e5�ϱ� �ƽ��ƽ��ϱ���.
�ƴ�, �׷��� �����غ��ϱ� ���� �迭 ������ �ʿ䵵 ����. 1����������, 2����������, 3���������� �̷��� �� �� ���� ���� ���ĵ�ä�� �������.
����Ʈ������ ������.
*/

int n;
vector<pii> players;
//vector<int> saikono_junban;

void print_players() {
	for (pii player : players) {
		cout << player.ff << ' ';
	}
	cout << endl;
	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pii piitmp = mp(tmp, i + 1);
		players.push_back(piitmp);
	}

	for (int i = 0; i < n; i++) {
		vector<pii>::iterator vctstart = players.begin();
		pii nowplayer = players[i];
		int jitsuryoku = players[i].ff;
		//cout << jitsuryoku << " �� �Ƿ��� ������ �ִ� ������ �����ұ��???" << endl;
		sort(vctstart, vctstart + i + 1, greater<pii>());

		vector<pii>::iterator now_iter = find(vctstart, vctstart + i, nowplayer);
		int now_idx = distance(vctstart, now_iter);
		//print_players();
		cout << min(now_idx, players[now_idx].ss) + 1 << endl;
		//cout << endl;
	}

	return 0;
}

/*
pair �ᵵ �ð��ʰ��߳�.
������ ����Ʈ�� ��߰ڴ�.
*/