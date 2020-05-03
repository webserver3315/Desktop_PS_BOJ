#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
//#include <bits/stdc++.h>
using namespace std;

#define MAX_DIC_SIZE 1000
#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 16

static char dic[MAX_DIC_SIZE][MAX_WORD_LENGTH + 1];
static char line[MAX_LINE_LENGTH];
static unsigned int dic_size;
static unsigned int line_len;

/*
암호문 line의 k번째 위치 이후 처음 나타나는 단어를 사전의 단어와 일치시켜보고, map/inv와 일관되는 mapping인지 검사하면서 계속 탐색한다.
*/
int search(unsigned int k, char* map, char* inv) {
	char word[MAX_WORD_LENGTH + 1];
	char map2['z' + 1], inv2['z' + 1];
	unsigned int i, j, t;
	char c;
	while (line[k] == ' ')//끝 업데이트
		k++;

	if (k >= line_len) {//k가 끝에 도달했으면 평문 출력 후 돌아간다
		for (i = 0; i < line_len; i++)
			putchar(line[i] == ' ') ? ' ' : map[line[i]];
		putchar('\n');
		return 1;
	}

	for (t = 0; line[k + t] >= 'a' && line[k + t] <= 'z'; t++)
		word[t] = line[k + t];
	word[t] = '\0';
	for (i = 0; i < dic_size; i++)
		if (strlen(dic[i]) == t) {
			for (c = 'a'; c <= 'z'; c++) {
				map2[c] = map[c];
				inv2[c] = inv[c];
			}
			for (j = 0; j < t; j++)
				if (map[word[j]] && map2[word[j]] != dic[i][j] || inv2[dic[i][j]] && inv2[dic[i][j]] != word[j])//아놔 ㅆㅂ 가독성 좀; 괄호 좀 박으라고
					goto end_of_loop_i;
				else {
					map2[word[j]] = dic[i][j];
					inv2[dic[i][j]] = word[j];
				}
			if (search(k + t, map2, inv2))
				return 1;
		end_of_loop_i:;
		}
	return 0;
}

//cpp로 해서인지 답이 제대로 안나온다.
int main() {
	char map['z' + 1], inv['z' + 1];
	unsigned int i;

	scanf("%d", &dic_size);
	//gets(line);
	gets_s(line, sizeof(line));
	for (i = 0; i < dic_size; i++)
		gets_s(dic[i],sizeof(dic[i]));
	while (gets_s(line, sizeof(line)) && *line != EOF) {
		line_len = strlen(line);
		for (i = 'a'; i <= 'z'; i++) {
			map[i] = '\0';
			inv[i] = '\0';
		}
		if (!search(0, map, inv)) {
			for (i = 0; i < line_len; i++)
				putchar(line[i] == ' ' ? ' ' : '*');
			putchar('\n');
		}
	}
	return 0;
}