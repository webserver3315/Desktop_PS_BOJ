#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define MAX (int)1e5+1
#define endl '\n'
using namespace std;

int N;
bool visited[MAX];
int parent[MAX];
vector<int> children[MAX];//vct<int>가 MAX가지 생성되는 것이다.

void makeParentArr(int nodeNum) {
	visited[nodeNum] = true;
	for (int i = 0; i < children[nodeNum].size(); i++) {
		int next = children[nodeNum][i];
		if (!visited[next]) {
			parent[next] = nodeNum;
			makeParentArr(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a; int b;
		cin >> a >> b;
		children[a].push_back(b);
		children[b].push_back(a);
	}
	makeParentArr(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << endl;
	}
	return 0;
}