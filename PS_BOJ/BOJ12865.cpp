#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#define MAX (int)1e5+2
#define LIM 101
using namespace std;

int N, K;
int wnv[MAX];//wnv[weight]=value

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		if (wnv[w] < v)
			wnv[w] = v;
	}


	return 0;
}