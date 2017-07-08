/*
 *  Author: JongYun, Jung
 */

#include <stdio.h>
const int SIZE = 100;
int mystrlen(char str[]);

int pos[SIZE], top;
void BURUTE_FORCE_MATCH(char t[], char p[])
{
	int n = mystrlen(t);
	int m = mystrlen(p);

	for(int i = 0; i <= n - m; i++)
	{
		int j;
		for(j = 0; j < m; j++)
			if(t[i + j] != p[j]) break;

		if(j == m){
			pos[top++] = i;
			i = i + m - 1;
		}
	}
}

int main(){

	char t[] = "alsjasmkdfkljjasmiwqpoinmmvmasjasmonvasoirjelas.jasmmvaosifjrowqij";
	char p[] = "jasm";
	BURUTE_FORCE_MATCH(t, p);

	for(int i = 0; i < top; i++)
		puts(t + pos[i]);
	return 0;
}

int mystrlen(char str[]){
	int len = 0;
	while(str[len]) len++;
	return len;
}
