#include <queue>
#include <iostream>
#include <algorithm>
//#define swap(type, a, b) do{type tmp=a;  a=b; b=tmp;}while(0)
#define endl '\n'
using namespace std;

int T, N;
priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

void printminHeap(priority_queue<int, vector<int>, greater<int>> q) {
	cout << "상단부: ";
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}

void printmaxHeap(priority_queue<int> q) {
	cout << "하단부: ";
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}

int pushSandClock(int n) {//상단 최소힙 하단 최대힙으로 구성된 모래시계형 힙쌍에 하단부터 넣는다.
	maxHeap.push(n);
	if (maxHeap.size() == minHeap.size() + 1) {//가운데가 없다
		if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int ut = minHeap.top(); int dt = maxHeap.top();
			minHeap.pop(); maxHeap.pop();
			minHeap.push(dt); maxHeap.push(ut);
		}
		//printminHeap(minHeap); printmaxHeap(maxHeap);
		return maxHeap.top();
	}
	else if (maxHeap.size() == minHeap.size() + 2) {//가운데가 있고 아랫단에 있다.
		int Dmax = maxHeap.top();
		maxHeap.pop(); minHeap.push(Dmax);
		//printminHeap(minHeap); printmaxHeap(maxHeap);
		return maxHeap.top();
	}
	else {
		cerr << "ERROR" << endl;
		exit(-1);
	}
}



void clearMaxHeap(priority_queue<int>& q) {
	priority_queue<int> empty;
	swap(q, empty);
}
void clearMinHeap(priority_queue<int,vector<int>,greater<int>>& q) {
	priority_queue<int, vector<int>, greater<int>> empty;
	swap(q, empty);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		clearMaxHeap(maxHeap); clearMinHeap(minHeap);
		cout << N / 2 + 1 << endl;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			int ans = pushSandClock(tmp);
			if (i % 2 == 0)
				cout << ans << ' ';
			if (i % 20 == 19)
				cout << endl;
		}
		cout << endl;
	}

	return 0;
}//구현에 52분소요