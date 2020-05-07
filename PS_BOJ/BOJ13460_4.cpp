/*
구슬탈출2

1. 문제를 정확히 읽는다
2. 예제 뇌이징을 거쳐 설계를 완벽히 한다.
3. 나눌 경우의 수를 확인한다
4. 총 쓰여질 초기화할 변수를 정리한다.
5. 가지치기를 구현한다.
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

struct Jyotai {//현 상태
	int red_r, red_c;
	int blue_r, blue_c;
	int kaisu;//횟수
};
int R, C;/*세로 가로*/
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0,0,-1,1 };
int map[10][10];/*0:벽, 1: 빈공간, 2:구멍,*/

/*
타인의 코드를 간략히 3건 참조한 결과, 간과하거나 놓친 부분이 있다.
1. 최적해를 찾는 것이므로 DFS가 아니라 BFS다. 즉 while(!queue.empty())를 쓰면 된다
2. 공은 각 색마다 단 1개씩만 주어진다. 따라서 공 좌표만 따로 유지하는게 편하다.
3. 2차원평면이므로 r, c방향 이동경우의 수를 배열로 나타내 이동시키는게 편하다.

구체적 안
1. 기본적으로 move 함수는 상하좌우 다 ㄱㄴ토록 추상적으로 짠다.
2. 이동은 queue.pop시마다 이루어지는데, 일단 red랑 blue를 다 가능한 한 옮긴다. 그 후, 겹치는지를 조사한다.
3. 겹친다면, 과거좌표가 업데이트된 좌표와 가까웠던 공이 그 자리를 선점토록 하고, 그 외의 공은 한칸 후퇴시킨다.
4. 이 과정을 BFS로 구현해야한다. queue에 들어가는 것은 board의 상황이 아니라 ball의 좌표다.
5. 다시 생각해보니까, queue.empty를 조건으로 while문 돌리는 것 보다는 일단 상한선 depth==10까지로 걸어놓고, 빨간공 들어가기전까지는 10까지 간다는 각오로 가는게 맞겠다.
6. 그런데 또 다시 생각해보니까, queue도 필요하다. 상하좌우로 움직이는것만해도 4배씩 늘어난다. depth는 공에 유지하도록 해야하나. queue empty로 돌리되, kaisu가 10이상이면 문답무용으로 제끼는걸로.

돌리다가 그냥 파란공이 쏙 들어가버린다고해서 이전처럼 바로 재기불능판정때리면 안된다!
파란공은 4번만에, 빨간공은 7번만에 넣을 수 있다면 -1이 아니라 7을 출력해야하는게 맞다! 단, 파란공이 반드시 들어가게끔 되어있으면 당연히 -1이다.

*/

int printMap(Jyotai Ima) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (Ima.blue_r == r && Ima.blue_c == c) {
				cout << "B" << ' ';
				continue;
			}
			else if (Ima.red_r == r && Ima.red_c == c) {
				cout << "R" << ' ';
				continue;
			}
			else if(map[r][c]==1)
				cout << '#' << ' ';
			else if (map[r][c] == 2) {
				cout << '.' << ' ';
			}
			else if (map[r][c] == 0) {
				cout << 'O' << ' ';
			}
		}
		cout << endl;
	}
	cout << '\n' << '\n';
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<Jyotai> JyotaiQueue;

	int hajime_b_c, hajime_b_r, hajime_r_c, hajime_r_r;
	int kotae;
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		string str;
		cin >> str;
		for (char& c : str) {/*의도대로 안되길래 아래 주석처럼 기존방식대로 짜려다 한번 auto&하니까 의도대로 되길래, 한번 char&해도 되었다. 결론, &이 필수였다.
							 내 추측으론, 주소값연산에 의존하는 부분이 있는데 &를 붙이지 않고 그냥 char를 선언할 시 str의 주소를 그대로 쓰는게 아니라, 새로 공간을 파는 모양이다.*/
			if ('#' == c) {
				map[r][&c - &str[0]] = 1;
			}
			else if ('O' == c) {
				map[r][&c - &str[0]] = 0;
			}
			else {/*그외 공 포함한 모든 빈공간은 2로 채운다.*/
				if ('B' == c) {
					hajime_b_c = &c - &str[0];
					hajime_b_r = r;
				}
				else if ('R' == c) {
					hajime_r_c = &c - &str[0];
					hajime_r_r = r;
				}
				map[r][&c - &str[0]] = 2;
			}
		}
		//for (int i = 0; i < C; i++) {
		//	char c = str[i];
		//	if ('#' == c) {
		//		map[r][&c - &str[0]] = 1;
		//	}
		//	else if ('O' == c) {
		//		map[r][&c - &str[0]] = 0;
		//	}
		//	else {/*그외 공 포함한 모든 빈공간은 2로 채운다.*/
		//		if ('B' == c) {
		//			hajime_b_c = &c - &str[0];
		//			hajime_b_r = r;
		//		}
		//		else if ('R' == c) {
		//			hajime_r_c = &c - &str[0];
		//			hajime_r_r = r;
		//		}
		//		map[r][&c - &str[0]] = 2;
		//	}
		//}
	}

	Jyotai HatsuJyotai = { hajime_r_r, hajime_r_c, hajime_b_r, hajime_b_c, 0 };
	JyotaiQueue.push(HatsuJyotai);
	while (!JyotaiQueue.empty()) {
		Jyotai ImaJyotai = JyotaiQueue.front();//back아니다!!!!!!!!!!!아아아아아아 시발 실화냐...
		JyotaiQueue.pop();
		if (ImaJyotai.kaisu >= 10) {
			continue;
		}

		int br = ImaJyotai.blue_r; int bc = ImaJyotai.blue_c; int rr = ImaJyotai.red_r; int rc = ImaJyotai.red_c;
		for (int i = 0; i < 4; i++) {
			/*어떻게 서로 다른 두 가지의 공을 끝까지 밀고나갈 것인가... 또한 충돌현상을 해결할 것인가...
			전진예정칸에 2가 저장되어있는 한, ㅈㄴ 달린다.
			다른 색공 또한 똑같이 일단 ㅈㄴ 달린다.
			멈추는 원인은 2가지다. 벽, 구멍. 부딪히는건 추후해결이므로 멈추지 않는다.
			이 상황에서 멈춘 원인이 1이 아니라 0이라면, 색을 파악한다. blue면 queue에 안넣고 해당 안 자체를 폐기한다. red면 게임 끝이다. 현재 kaisu 출력한다.
			충돌했다면 br과 brbr, 등등을 비교한다. 변위가 짧은 쪽이 먼저 도달한 것이므로, 짧은변위의 공이 위치를 차지하고, 긴변위의 공은 한 칸 후퇴한다.
			ㅈㄴ달리는건 while문으로 구현하자.
			kaisu 빼먹지말고 업데이트시켜줄 것
			*/
			int kaisukaisu = ImaJyotai.kaisu + 1;
			int brbr = br; int bcbc = bc; int rrrr = rr; int rcrc = rc;
			while (map[brbr + dr[i]][bcbc + dc[i]] == 2) {
				brbr += dr[i], bcbc += dc[i];
			}

			while (map[rrrr + dr[i]][rcrc + dc[i]] == 2) {
				rrrr += dr[i], rcrc += dc[i];
			}

			/*전방분석_ 구멍 파 빨 형식의 예제에 유의하자.*/
			if (map[brbr + dr[i]][bcbc + dc[i]] == 0) {/*만약 파란공이 구멍때문에 멈춘거였으면, 해당턴에 빨간공이 먼저 들어간다한들 동일턴이므로 무효처리다. 즉 더 강하다.*/
				continue;/*딴방향 알아봅시다*/
			}
			else if (map[rrrr + dr[i]][rcrc + dc[i]] == 0) {/*파란공이 구멍에 안들어간 채, 빨간공이 구멍에 들어갔다면 게임끝이다.*/
				kotae = kaisukaisu;
				goto Finale;
			}

			/*구멍에 들어간게 아닐 경우, 충돌시 처리*/
			if (brbr == rrrr && bcbc == rcrc) {
				bool BlueIsChikai = false;//사실 쓸모없지만 가독성 ㅆㅅㅌㅊ되므로 보존함
				if (abs(brbr - br) + abs(bcbc - bc) < abs(rcrc - rc) + abs(rrrr - rr)) {
					BlueIsChikai = true;
					rcrc -= dc[i], rrrr -= dr[i];
				}
				else {
					bcbc -= dc[i], brbr -= dr[i];
				}
			}
			/*큐에 넣기*/
			if (rrrr == rr && rcrc == rc && brbr == br && bcbc == bc)/*두 공의 좌표가 바뀐게 없으면 큐에 굳이 넣지 말자.*/
				continue;
			Jyotai AtarashiiJyotai = { rrrr,rcrc,brbr,bcbc,kaisukaisu };
			JyotaiQueue.push(AtarashiiJyotai);
			//printMap(AtarashiiJyotai);
		}
	}
	/*큐가 다 빌때까지 결국 답이 없었으니, -1판정 때린다.*/
	cout << -1 << endl;
	return 0;
Finale:
	cout << kotae << endl;
	return 0;
}