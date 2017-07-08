/*
 *  KMP 알고리즘
 *  Author: JongYun, Jung
 */

#include <stdio.h>
const int SIZE = 100;

int pos[SIZE], top;
void KMP(char t[], char p[])
{
	int n = 0, m = 0;
	while(t[n]) n++; while(p[m]) m++;

	// 패턴 전처리

	// 패턴 매칭
}

int main(){

	char t[] = "alsjasmkdfkljjasmiwqpoinmmvmasjasmonvasoirjelas.jasmmvaosifjrowqij";
	char p[] = "jasm";
	BURUTE_FORCE_MATCH(t, p);

	for(int i = 0; i < top; i++)
		puts(t + pos[i]);
	return 0;
}
