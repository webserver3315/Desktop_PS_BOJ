/*
가능한 시험점수
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&categoryId=AWHPkqBqAEsDFAUn&categoryType=CODE
*/

#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;

/*삼성문제가 늘 그렇듯이 일단 테스트케이스 수 T부터 박고
각 T마다 문제의 수인 자연수 개수 N이 주어진다. 100 이하의 자연수임이 보장된다.
각 배점은 100 이하의 자연수이다.
각 문제마다의 배점은 다 다르며, 학생이 맞을 수 있는 배점의 종류를 출력하자.

일단 내 생각.
100 이하의 배점이며 문제 또한 100개를 넘지 않는다.
따라서, 기수정렬식으로 해도 상관없지않나? 0점부터 10000점까지가 한계니까 true나 false로 유지하는게 나을 듯 하다.

모든 문제에 대해 주어지는 경우는 단 두가지다. 맞추거나 틀리거나.
그러므로 미연시식 DFS를 적용한다.
순서바뀐 선지는 동일선지로 인지하므로 전진만 하면 되고, combination으로 구현하면 된다.

이미 있으면 그대로, 들르지 않은 점수라면 false 를 true로 해당 visit[value]의 값을 바꾼다.
그리고 최종적으로 true된 visit의 수를 출력한다.
*/

int T;

void PrintVisited(vector<bool>& visit) {
	int i = 0;
	for (auto tmp : visit) {
		if (tmp == true) {
			cout << i << ' ';
		}
		i++;
	}
	cout << endl;
	return;
}

int KazoeruVisit(vector<bool>& visit) {
	int Cnt = 0;
	for (auto tmp : visit) {
		if (tmp == true) {
			Cnt++;
		}
	}
	return Cnt;
}

void Combination(int start, int end, int sum, vector<bool>& visit, vector<int>& scores) {
	if (start == end) {
		//cout << "출력" << endl;
		return;
	}
	for (int i = start; i < end; i++) {
		sum += scores[i];
		//cout << scores[i] << "을 더해서 현재 " << sum << " 이 되었습니다" << endl;
		if (!visit[sum]) {
			visit[sum] = true;
			Combination(i + 1, end, sum, visit, scores);
		}
		sum -= scores[i];
		if (!visit[sum])//굳이 필요없지만 아무것도 고르지 않는 경우를 구하기 위해서 필요한 코드다. 속도면에서는 이 코드를 빼고 출력되는 답에 일괄적으로 +1 하는게 좀더 빠르다.
			visit[sum] = true;
		//cout << scores[i] << "을 빼서 현재 " << sum << " 이 되었습니다" << endl;
		Combination(i + 1, end, sum, visit, scores);
	}
	return;
}

/*문제 수 N을 인자로 받고, set을 유지한다.
N까지의 인자를 각각 visit의 모든 원소에 대해 더하고, 만약 겹쳐지면 insert, 아니면 넘어간다.

*/
void DP(int N, set<int>& visit, vector<int> scores) {
	for (int i = 0; i < N; i++) {
		int end = visit.size();
		set<int>::iterator iter = visit.begin();
		for (int idx = 0; idx < end; iter++, idx++) {
			int tmp = *iter;
			int tmptmp = tmp + scores[i];
			//cout << tmptmp << " = " << tmp << " + " << scores[i] << endl;
			visit.insert(tmptmp);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	/*for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		vector<bool> visit(10000, false);
		vector<int> scores; scores.reserve(100);
		for (int idx = 0; idx < N; idx++) {
			int tmp;
			cin >> tmp;
			scores.push_back(tmp);
		}
		cout << "#" << i << ' ';
		Combination(0, scores.size(), 0, visit, scores);
		cout << KazoeruVisit(visit) << endl;
		//PrintVisited(visit);
	}*/
	
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		set<int> visit;
		vector<int> scores; scores.reserve(100);
		for (int idx = 0; idx < N; idx++) {
			int tmp;
			cin >> tmp;
			scores.push_back(tmp);
		}
		visit.insert(0);
		DP(N, visit, scores);
		cout << "#" << i << ' ';
		cout << visit.size() << endl;
		//PrintVisited(visit);
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}