/*
N��M 9
�ߺ��� ���Ǵ� ��ǲ�� �־��� ��, ������ ����϶�
*/

#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���

using namespace std;

int N, M;
bool visited[10];
vector<int> mystack;
set<vector<int>> mukashi;
vector<int> kouhou;

/*
M<=N�ӿ� �����ؾ��ϰ�,
1 1 1 1 �� �Է¹޾Ұ� 4�ڸ��� ����ؾ��Ѵٸ� 1 1 1 1�� ����ؾ� �Ѵ�.
�Ȱ��� ������, 1 1 3 4 �� �Է¹޾Ұ� 4�ڸ��� ����ؾ��Ѵٸ� 1 1 3 4�� ����ؾ� �Ѵ�.
���, �� ���������� �ߺ� �Ÿ��ڴٰ� set�� ���� �ȵȴ�. �ߺ����ҵ� �ᱹ ���̴� ���̽��� �ִ�.

1 7 9 9�� �Է��Ѵٸ�, 2���� �̴´ٰ� ���� �� 9 9 �� �ݵ�� ���� �Ѵ�.
��? �׷��� 2 4 4 ���� 1������ �̴´ٸ� 4�� 1���ۿ� �ȳ����µ�... 4�� ���̽��� 2�� �����°� �ƴ϶�...
��, ���̽��� unique �ؾ��� ���Ұ� unique ������ ����� ������. ������ 9 9�� ������ ���°� �ƴϴ� �� �ǳ�. ������ unique �� ���̽��� ��� ���� �����ϴ� ���̴�.
�׷��ٸ�, ���̽��� set�� �ְ� ������ find ���θ� ������ �� ���� ������. find �Ǹ� �Ÿ���, find �ȵǸ� �ش� ���̽��� �ִ´�.

��ͷ� Ǯ �� ��������. �ϴ� naive �� �����δ� set �� find �� ����ϴ� ���� ���� �������� �Ѵ�.

��, ��ͷ� Ǭ�ٸ�
�׳� �Ϲ������� Ǯ��,
���� ��°��� ���� ��°��� ���ٸ� �Ÿ��� ������ ���� ������ �κ� �ƴѰ�?
���� ��°��� ��� ���� �����س��� �ʿ䵵 ����, ���� ŷ�����̱�.

���� ���Ϳ� �Ʊ��� ����(==mystack) �� ���ϴµ� == �����ڸ� ����Ѵٸ�, ��1����=�纤���� size, ��2����: ������ ����
����, ���Ϳ��� = �����ڰ� ������ �����Ѱ�? �����ϴٸ�, ��������� �����Ѱ� �ƴϸ� ������ �ּҸ� ���������ϴ°�? >>> ���������. copies all the element from x into the container ��� ���ۿ� �Ǿ��ִ�.

�ݷ�: 1 1 2 2
��, �ȵǰڴ�. �ϴ� set �Ἥ Ǯ��� ����.
*/

void Permutation3(int depth) {
	if (depth == M) {
		if (mukashi.find(mystack) != mukashi.end())
			return;
		mukashi.insert(mystack);
		for (int tmp : mystack)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		mystack.push_back(kouhou[i]);
		Permutation3(depth + 1);
		mystack.pop_back();
		visited[i] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		kouhou.push_back(tmp);
	}
	sort(kouhou.begin(), kouhou.end());

	Permutation3(0);


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}

/*�ı�
input�� �ߺ����������� output�� �ߺ��Ұ��� �ϴ� �� set�� �ٷ� �Ἥ Ǯ���µ�
��� �� ���� ������ ���� �ƴ� M���� ���� ���� �� �ֱ⿡ set �� �־� ������ �ߺ��˻縦 �ϴ� ���� ��ȿ������ ���̴�.

2��Ǯ�̸� ����, ��͵Ǵ� ���Լ����� for�� �� ���� value �� �����ϰ� ȣ��ǰԲ� �ϸ� ���� set�� ���� �ʰ� �ߺ�output�� ���� �� �ִ�.
*/