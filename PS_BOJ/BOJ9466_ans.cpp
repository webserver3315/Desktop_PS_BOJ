/*
텀 프로젝트
참조 : https://jaimemin.tistory.com/674
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100005

using namespace std;
int T;/*테스트 케이스 수*/
int N, cnt;/*학생 수, 카운팅*/
int want[MAX];/*i 인자가 가리키는 노드*/
int visited[MAX];/*임시방문표시*/
int done[MAX];/*완전방문각인. ㄹㅇ로 팀을 이룬 노드.*/

/*
검색 중
임시방문 yes, 완전방문 no: 신규사이클
yes yes : 불가능.
no yes : 불가능. 애초에 done 되었으므로 걸러져야 정상
no no: 일반적. 그냥 전진하면 됨. 신규사이클인지 꽝인지는 불확실한 단계
*/
void dfs(int nodenum) {/*nodenum을 탐색한다.*/
	visited[nodenum] = 1;/*임시방문표시 때리고*/
	int next = want[nodenum];/*다음방문예고인자를 지정해준다*/
	if (0 == visited[next])/*하지메마시테라면*/ {
		// printf("dfs(%d) 호출\n",next);
		dfs(next);/*재귀를 통해 가능한 한 traverse한다.*/
	}
	else if (0 == done[next]) {/*검색 중 중복되어 만났으며, 그 것이 done되지 않았다면, 신규 사이클이라는 뜻이므로*/
		// printf("done(%d)이 0이다\n",next);
		for (int i = next; i != nodenum; i = want[i])/*한 번 더 순회하며 cnt++하고*/ {
			// printf("i는 %d, nodenum은 %d, cnt++\n",i,nodenum);
			cnt++;
		}
		cnt++;/*자기자신까지 ++해주는걸 잊지말자*/
	}
	done[nodenum] = 1;/*visited and done 이라면 해당노드에 완전방문각인을 새긴다.*/
	// printf("\n");
}

int main() {
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();


	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));/*테스트케이스마다 visited done 0으로 초기화*/
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &want[j]);
		}
		// puts("여기까지 왔다");
		cnt = 0;
		for (int j = 1; j <= N; j++) {/*전 노드 순회*/
			// printf("done[%d] 조사중\n",j);
			if (!done[j]) {
				/*임시방문 안된 노드에 한해서 >>> done 안된 노드에 한해서가 더 맞지 않나?*/
				// printf("dfs(%d) 최초호출\n",j);
				dfs(j);
			}
		}
		printf("%d\n", N - cnt);
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;

	return 0;
}