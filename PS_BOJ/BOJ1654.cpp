/*
랜선 자르기
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*동일한 길이로 잘라야 하므로
가능범위는 일단 0~최단값 사이이다.
이진서치 ㄱㄱ*/

#define MAX 10005

int N, K;
int minlan, maxlan, kouhou;
//int lan[MAX];
vector<int> lan;//범위지정for문 쓰기 위해 벡터로

void psearch() {/*min과 max의 평균값인 kouhou로 모든 랜선을 나눠서 몇 가닥의 랜선이 생성되는지 계산
			   만일, max와 min이 동등해지거나 역전되면 해당 길이를 리턴
			   만일, 부족하면 max를 kouhou, kouhou랑 min의 평균값으로 kouhou를 업데이트한 후 다시 ㄱㄱ
			   만일, 과하면 min을 kouhou, kouhou랑 max의 평균값으로 kouhou를 업데이트한 후 다시 ㄱㄱ  
			   수학적으로 허용되는 최대의 kouhou값을 찾는 것이다
			   */
	while (minlan <= maxlan) {
		int lankazu = 0;
		for (int length : lan) {
			lankazu += length / kouhou;
		}
		if (lankazu < K) {//랜선이 적게 생성됨. kouhou를 짧게 해서 더 잘게 잘라야함
			//cout << "minlan: " << minlan << " kouhou: " << kouhou << " maxlan: " << maxlan << " lankazu: " << lankazu << " 랜선이 적게 생성됨. kouhou랑 maxlen 줄입니다" << endl;
			maxlan = kouhou - 1;
			kouhou = (minlan + maxlan) / 2;
		}
		else{//랜선이 많이 생성됨. 과하게 짧게 자른 것이므로 수정필요
			//cout << "minlan: " << minlan << " kouhou: " << kouhou << " maxlan: " << maxlan << " lankazu: " << lankazu << " 랜선이 많이 생성됨. kouhou랑 minlen 늘립니다" << endl;
			minlan = kouhou + 1;
			kouhou = (minlan + maxlan) / 2;
		}
	}
}

/*난관은, K가 N보다 작을 시에도 어떻게 구할 것이냐 하는 것.*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		lan.push_back(tmp);
	}
	sort(lan.begin(), lan.end());
	//maxlan = lan[0];
	maxlan = lan.back();
	kouhou = (minlan + maxlan) / 2;
	
	psearch();

	cout << kouhou << endl;

	return 0;
}