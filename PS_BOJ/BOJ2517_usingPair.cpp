/*
달리기
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
세그먼트 트리가 왜 나왔는가?
값이 빈번히 바뀌는 배열에서 이웃한 항들을 연산할 필요가 있을 때, 합배열로도 최적화가 불가능한 경우를 빠르게 검색하기 위함이다.
*/

/*
선수 수는 5e5 이하. 겹치는 실력 없음.
*/

/*
아니, 이거 그냥 내림차순대로 sort한 뒤, 원래 위치랑 내림차순 뒤 위치 중 min값 출력하면 안되나?
안된다. 뒤의 실력자가 자신을 제치지 않았다는 전제가 필요하다.
그렇다면, 자신부터 1등까지에 대해서만 돌리면 되는 것 아닌가?
그런데, 그렇다고 하면 각각의 선수에 대해 전부 sort를 돌려야하는데, log5e5를 5e5번 반복하게 되므로 30e5가 된다. 3e6이므로 1초면 ㅆㄱㄴ하긴 한데...
sort 돌리고, 자기 어디에있는지 찾고, 그걸 반복.
logN * logN(이진) * N = 180e5니까 아슬아슬하구만.
아니, 그런데 생각해보니까 새로 배열 선언할 필요도 없다. 1개원소정렬, 2개원소정렬, 3개원소정렬 이렇게 갈 때 앞의 것이 정렬된채라도 상관없다.
세그트리없이 가보자.
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
		//cout << jitsuryoku << " 의 실력의 선수는 최대 몇등까지 가능할까요???" << endl;
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
pair 써도 시간초과뜨네.
ㄹㅇ로 세그트리 써야겠다.
*/