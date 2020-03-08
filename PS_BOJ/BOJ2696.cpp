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
	cout << "��ܺ�: ";
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}

void printmaxHeap(priority_queue<int> q) {
	cout << "�ϴܺ�: ";
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}

int pushSandClock(int n) {//��� �ּ��� �ϴ� �ִ������� ������ �𷡽ð��� ���ֿ� �ϴܺ��� �ִ´�.
	maxHeap.push(n);
	if (maxHeap.size() == minHeap.size() + 1) {//����� ����
		if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int ut = minHeap.top(); int dt = maxHeap.top();
			minHeap.pop(); maxHeap.pop();
			minHeap.push(dt); maxHeap.push(ut);
		}
		//printminHeap(minHeap); printmaxHeap(maxHeap);
		return maxHeap.top();
	}
	else if (maxHeap.size() == minHeap.size() + 2) {//����� �ְ� �Ʒ��ܿ� �ִ�.
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
}//������ 52�мҿ�