/*
∫ŒµÓ»£
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'
using namespace std;

int N;
string futougo;
vector<int> answer_max;
bool ended_max;
vector<int> answer_min;
bool ended_min;
bool visit[13];

void min_dfs(int now) {
	if (ended_min)
		return;
	if (now == N) {
		ended_min = true;
		for (int tmp : answer_min)
			cout << tmp;
		cout << endl;
		return;
	}

	if (answer_min.empty()) {
		for (int i = 0; i < 10 && !ended_min; i++) {
			visit[i] = true;
			answer_min.push_back(i);
			min_dfs(now);
			visit[i] = false;
			answer_min.pop_back();
		}
	}
	if (futougo[now] == '<') {
		for (int i = 0; i < 10 && !ended_min; i++) {
			if (visit[i] || (!answer_min.empty() && answer_min.back() >= i))
				continue;
			visit[i] = true;
			answer_min.push_back(i);
			min_dfs(now + 1);
			visit[i] = false;
			answer_min.pop_back();
		}
	}
	else if (futougo[now] == '>') {
		for (int i = 0; i < 10 && !ended_min; i++) {
			if (visit[i] || (!answer_min.empty() && answer_min.back() <= i))
				continue;
			visit[i] = true;
			answer_min.push_back(i);
			min_dfs(now + 1);
			visit[i] = false;
			answer_min.pop_back();
		}
	}
	/*else
		cout << "ERROR" << endl;*/
}

void max_dfs(int now) {
	if (ended_max)
		return;
	if (now == N) {
		ended_max = true;
		for (int tmp : answer_max)
			cout << tmp;
		cout << endl;
	}

	if (answer_max.empty()) {
		for (int i = 9; i >= 0 && !ended_max; i--) {
			visit[i] = true;
			answer_max.push_back(i);
			max_dfs(now);
			visit[i] = false;
			answer_max.pop_back();
		}
	}
	else if (futougo[now] == '<') {
		for (int i = 9; i >= 0 && !ended_max; i--) {
			if (visit[i] || (!answer_max.empty() && answer_max.back() >= i))
				continue;
			visit[i] = true;
			answer_max.push_back(i);
			max_dfs(now + 1);
			visit[i] = false;
			answer_max.pop_back();
		}
	}
	else if (futougo[now] == '>') {
		for (int i = 9; i >= 0 && !ended_max; i--) {
			if (visit[i] || answer_max.back() <= i)
				continue;
			visit[i] = true;
			answer_max.push_back(i);
			max_dfs(now + 1);
			visit[i] = false;
			answer_max.pop_back();
		}
	}
	/*else
		cout << "ERROR" << endl;*/
}

int main() {
	ios::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		futougo.append(tmp);
	}

	max_dfs(0);
	memset(visit, false, N);
	min_dfs(0);

	return 0;
}