/*
����Ż��2

1. ������ ��Ȯ�� �д´�
2. ���� ����¡�� ���� ���踦 �Ϻ��� �Ѵ�.
3. ���� ����� ���� Ȯ���Ѵ�
4. �� ������ �ʱ�ȭ�� ������ �����Ѵ�.
5. ����ġ�⸦ �����Ѵ�.
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

struct Jyotai {//�� ����
	int red_r, red_c;
	int blue_r, blue_c;
	int kaisu;//Ƚ��
};
int R, C;/*���� ����*/
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0,0,-1,1 };
int map[10][10];/*0:��, 1: �����, 2:����,*/

/*
Ÿ���� �ڵ带 ������ 3�� ������ ���, �����ϰų� ��ģ �κ��� �ִ�.
1. �����ظ� ã�� ���̹Ƿ� DFS�� �ƴ϶� BFS��. �� while(!queue.empty())�� ���� �ȴ�
2. ���� �� ������ �� 1������ �־�����. ���� �� ��ǥ�� ���� �����ϴ°� ���ϴ�.
3. 2��������̹Ƿ� r, c���� �̵������ ���� �迭�� ��Ÿ�� �̵���Ű�°� ���ϴ�.

��ü�� ��
1. �⺻������ move �Լ��� �����¿� �� ������� �߻������� §��.
2. �̵��� queue.pop�ø��� �̷�����µ�, �ϴ� red�� blue�� �� ������ �� �ű��. �� ��, ��ġ������ �����Ѵ�.
3. ��ģ�ٸ�, ������ǥ�� ������Ʈ�� ��ǥ�� ������� ���� �� �ڸ��� ������� �ϰ�, �� ���� ���� ��ĭ �����Ų��.
4. �� ������ BFS�� �����ؾ��Ѵ�. queue�� ���� ���� board�� ��Ȳ�� �ƴ϶� ball�� ��ǥ��.
5. �ٽ� �����غ��ϱ�, queue.empty�� �������� while�� ������ �� ���ٴ� �ϴ� ���Ѽ� depth==10������ �ɾ����, ������ ������������ 10���� ���ٴ� ������ ���°� �°ڴ�.
6. �׷��� �� �ٽ� �����غ��ϱ�, queue�� �ʿ��ϴ�. �����¿�� �����̴°͸��ص� 4�辿 �þ��. depth�� ���� �����ϵ��� �ؾ��ϳ�. queue empty�� ������, kaisu�� 10�̻��̸� ���乫������ �����°ɷ�.

�����ٰ� �׳� �Ķ����� �� �������ٰ��ؼ� ����ó�� �ٷ� ���Ҵ����������� �ȵȴ�!
�Ķ����� 4������, �������� 7������ ���� �� �ִٸ� -1�� �ƴ϶� 7�� ����ؾ��ϴ°� �´�! ��, �Ķ����� �ݵ�� ���Բ� �Ǿ������� �翬�� -1�̴�.

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
		for (char& c : str) {/*�ǵ���� �ȵǱ淡 �Ʒ� �ּ�ó�� ������Ĵ�� ¥���� �ѹ� auto&�ϴϱ� �ǵ���� �Ǳ淡, �ѹ� char&�ص� �Ǿ���. ���, &�� �ʼ�����.
							 �� ��������, �ּҰ����꿡 �����ϴ� �κ��� �ִµ� &�� ������ �ʰ� �׳� char�� ������ �� str�� �ּҸ� �״�� ���°� �ƴ϶�, ���� ������ �Ĵ� ����̴�.*/
			if ('#' == c) {
				map[r][&c - &str[0]] = 1;
			}
			else if ('O' == c) {
				map[r][&c - &str[0]] = 0;
			}
			else {/*�׿� �� ������ ��� ������� 2�� ä���.*/
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
		//	else {/*�׿� �� ������ ��� ������� 2�� ä���.*/
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
		Jyotai ImaJyotai = JyotaiQueue.front();//back�ƴϴ�!!!!!!!!!!!�ƾƾƾƾƾ� �ù� ��ȭ��...
		JyotaiQueue.pop();
		if (ImaJyotai.kaisu >= 10) {
			continue;
		}

		int br = ImaJyotai.blue_r; int bc = ImaJyotai.blue_c; int rr = ImaJyotai.red_r; int rc = ImaJyotai.red_c;
		for (int i = 0; i < 4; i++) {
			/*��� ���� �ٸ� �� ������ ���� ������ �а��� ���ΰ�... ���� �浹������ �ذ��� ���ΰ�...
			��������ĭ�� 2�� ����Ǿ��ִ� ��, ���� �޸���.
			�ٸ� ���� ���� �Ȱ��� �ϴ� ���� �޸���.
			���ߴ� ������ 2������. ��, ����. �ε����°� �����ذ��̹Ƿ� ������ �ʴ´�.
			�� ��Ȳ���� ���� ������ 1�� �ƴ϶� 0�̶��, ���� �ľ��Ѵ�. blue�� queue�� �ȳְ� �ش� �� ��ü�� ����Ѵ�. red�� ���� ���̴�. ���� kaisu ����Ѵ�.
			�浹�ߴٸ� br�� brbr, ����� ���Ѵ�. ������ ª�� ���� ���� ������ ���̹Ƿ�, ª�������� ���� ��ġ�� �����ϰ�, �亯���� ���� �� ĭ �����Ѵ�.
			�����޸��°� while������ ��������.
			kaisu ���������� ������Ʈ������ ��
			*/
			int kaisukaisu = ImaJyotai.kaisu + 1;
			int brbr = br; int bcbc = bc; int rrrr = rr; int rcrc = rc;
			while (map[brbr + dr[i]][bcbc + dc[i]] == 2) {
				brbr += dr[i], bcbc += dc[i];
			}

			while (map[rrrr + dr[i]][rcrc + dc[i]] == 2) {
				rrrr += dr[i], rcrc += dc[i];
			}

			/*����м�_ ���� �� �� ������ ������ ��������.*/
			if (map[brbr + dr[i]][bcbc + dc[i]] == 0) {/*���� �Ķ����� ���۶����� ����ſ�����, �ش��Ͽ� �������� ���� �����ѵ� �������̹Ƿ� ��ȿó����. �� �� ���ϴ�.*/
				continue;/*������ �˾ƺ��ô�*/
			}
			else if (map[rrrr + dr[i]][rcrc + dc[i]] == 0) {/*�Ķ����� ���ۿ� �ȵ� ä, �������� ���ۿ� ���ٸ� ���ӳ��̴�.*/
				kotae = kaisukaisu;
				goto Finale;
			}

			/*���ۿ� ���� �ƴ� ���, �浹�� ó��*/
			if (brbr == rrrr && bcbc == rcrc) {
				bool BlueIsChikai = false;//��� ��������� ������ ���������ǹǷ� ������
				if (abs(brbr - br) + abs(bcbc - bc) < abs(rcrc - rc) + abs(rrrr - rr)) {
					BlueIsChikai = true;
					rcrc -= dc[i], rrrr -= dr[i];
				}
				else {
					bcbc -= dc[i], brbr -= dr[i];
				}
			}
			/*ť�� �ֱ�*/
			if (rrrr == rr && rcrc == rc && brbr == br && bcbc == bc)/*�� ���� ��ǥ�� �ٲ�� ������ ť�� ���� ���� ����.*/
				continue;
			Jyotai AtarashiiJyotai = { rrrr,rcrc,brbr,bcbc,kaisukaisu };
			JyotaiQueue.push(AtarashiiJyotai);
			//printMap(AtarashiiJyotai);
		}
	}
	/*ť�� �� �������� �ᱹ ���� ��������, -1���� ������.*/
	cout << -1 << endl;
	return 0;
Finale:
	cout << kotae << endl;
	return 0;
}