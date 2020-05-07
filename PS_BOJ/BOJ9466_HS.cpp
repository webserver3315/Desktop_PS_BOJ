#include <iostream>
#include <memory.h>
using namespace std;
#define MAX 100010
int arr[MAX], T, N, visit[MAX];
int leftover, ncnt, least, nxt;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> N;
		ncnt = 0;
		for (int i = 1; i <= N; ++i)
			cin >> arr[i];
		memset(visit, 0, 4*(N+1));
		leftover = N;
		for (int i = 1; i <= N; ++i)
		{
			if (visit[i]) continue;

			least = ncnt;
			nxt = i;
			while (!visit[nxt]) {
				visit[nxt] = ncnt++; nxt = arr[nxt];
			}
			if (visit[nxt] >= least)
			{
				leftover += visit[nxt];
				leftover -= ncnt;
			}
		}
		cout << leftover << '\n';
	}
	return 0;
}