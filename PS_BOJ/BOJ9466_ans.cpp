/*
�� ������Ʈ
���� : https://jaimemin.tistory.com/674
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100005

using namespace std;
int T;/*�׽�Ʈ ���̽� ��*/
int N, cnt;/*�л� ��, ī����*/
int want[MAX];/*i ���ڰ� ����Ű�� ���*/
int visited[MAX];/*�ӽù湮ǥ��*/
int done[MAX];/*�����湮����. ������ ���� �̷� ���.*/

/*
�˻� ��
�ӽù湮 yes, �����湮 no: �űԻ���Ŭ
yes yes : �Ұ���.
no yes : �Ұ���. ���ʿ� done �Ǿ����Ƿ� �ɷ����� ����
no no: �Ϲ���. �׳� �����ϸ� ��. �űԻ���Ŭ���� �������� ��Ȯ���� �ܰ�
*/
void dfs(int nodenum) {/*nodenum�� Ž���Ѵ�.*/
	visited[nodenum] = 1;/*�ӽù湮ǥ�� ������*/
	int next = want[nodenum];/*�����湮�������ڸ� �������ش�*/
	if (0 == visited[next])/*�����޸����׶��*/ {
		// printf("dfs(%d) ȣ��\n",next);
		dfs(next);/*��͸� ���� ������ �� traverse�Ѵ�.*/
	}
	else if (0 == done[next]) {/*�˻� �� �ߺ��Ǿ� ��������, �� ���� done���� �ʾҴٸ�, �ű� ����Ŭ�̶�� ���̹Ƿ�*/
		// printf("done(%d)�� 0�̴�\n",next);
		for (int i = next; i != nodenum; i = want[i])/*�� �� �� ��ȸ�ϸ� cnt++�ϰ�*/ {
			// printf("i�� %d, nodenum�� %d, cnt++\n",i,nodenum);
			cnt++;
		}
		cnt++;/*�ڱ��ڽű��� ++���ִ°� ��������*/
	}
	done[nodenum] = 1;/*visited and done �̶�� �ش��忡 �����湮������ �����.*/
	// printf("\n");
}

int main() {
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();


	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));/*�׽�Ʈ���̽����� visited done 0���� �ʱ�ȭ*/
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &want[j]);
		}
		// puts("������� �Դ�");
		cnt = 0;
		for (int j = 1; j <= N; j++) {/*�� ��� ��ȸ*/
			// printf("done[%d] ������\n",j);
			if (!done[j]) {
				/*�ӽù湮 �ȵ� ��忡 ���ؼ� >>> done �ȵ� ��忡 ���ؼ��� �� ���� �ʳ�?*/
				// printf("dfs(%d) ����ȣ��\n",j);
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