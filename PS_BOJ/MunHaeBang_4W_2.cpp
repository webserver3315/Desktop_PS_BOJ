#include <bits/stdc++.h>
#define pii pair<int,int>
#define pfpii pair<float,pair<int,int>>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

/*
5���� �ð��� HH:MM ������� �Է�.
�� �ð����� ��ħ�� ��ħ�� ���� ����. ��ħ�� ��ħ�� ���� �� �̼��ϰ� �����δ�.
�� ���� median ���� ����ϸ� �ȴ�.
���� ���� ������ ��찡 �ִٸ�, earlier time�� �켱���Ѵ�.

00�� 0���� ��� �ð������ ���� �������� ���� ��, ��ħ�� �⺻������ 30���� 1�и��� 0.5�� �߰��ȴ�.
��ħ�� �д� 6����.

*/

int t;
vector<string> strvct;
vector<pfpii> pipiivct;//��, �ð� �� ��

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