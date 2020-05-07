#include <bits/stdc++.h>
#define pii pair<int,int>
#define pfpii pair<float,pair<int,int>>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

/*
5개의 시간을 HH:MM 방식으로 입력.
각 시간마다 시침과 분침의 각을 유지. 시침은 분침에 따라 또 미세하게 움직인다.
그 각의 median 값을 출력하면 된다.
만일 각이 동일한 경우가 있다면, earlier time을 우선시한다.

00을 0도로 잡고 시계방향을 양의 방향으로 잡을 때, 시침은 기본적으로 30도에 1분마다 0.5도 추가된다.
분침은 분당 6도다.

*/

int t;
vector<string> strvct;
vector<pfpii> pipiivct;//각, 시간 및 분

float getangle(const pii& time) {
	float hourang = 0; float minang = 0;
	int hour = time.ff; int minute = time.ss;
	if (hour > 12)
		hour -= 12;
	hourang = hour * 30 + minute * 0.5;
	minang = minute * 6;
	float diffang = abs(hourang - minang);
	if (diffang > 180)
		return 360 - diffang;
	else
		return diffang;
}

pii str2pii(const string& str) {
	int hour = 0; int min = 0;
	hour += 10 * (str[0] - '0'); hour += str[1] - '0';
	min += 10 * (str[3] - '0'); min += (str[4] - '0');
	return mp(hour, min);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		strvct.clear(); pipiivct.clear();
		for (int i = 0; i < 5; i++) {
			string tmp;
			cin >> tmp;
			strvct.push_back(tmp);
		}
		for (auto a : strvct) {
			pii time = str2pii(a);
			float angle = getangle(time);
			pipiivct.push_back(mp(angle,time));
		}
		sort(pipiivct.begin(), pipiivct.end());
		int hour = pipiivct[2].ss.ff; int minute = pipiivct[2].ss.ss;
		string hourstr = to_string(hour); string minutestr = to_string(minute);
		if (hour < 10) {
			hourstr = "0";
			hourstr.push_back('0' + hour);
		}
		if (minute < 10) {
			minutestr = "0";
			minutestr.push_back('0' + minute);
		}
		//cout << pipiivct[2].ss.ff << ':' << pipiivct[2].ss.ss << endl;
		cout << hourstr << ':' << minutestr << endl;
	}

	return 0;
}