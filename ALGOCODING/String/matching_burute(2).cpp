/*
 *  Author: JongYun, Jung
 */

#include <stdio.h>
const int SIZE = 100;
int mystrlen(char str[]);

int pos[SIZE], top;		// t[]���� p[]�� ��ġ ����
void BURUTE_FORCE_MATCH(char t[], char p[])
{
	int n = mystrlen(t);
	int m = mystrlen(p);

	int i = 0, j = 0;
	while(i < n)
	{
		if(p[j] != t[i]){	// ����ġ
			i = i - j;		// ó�� ���� ��ġ
			j = -1;
		}
		i++, j++;
		if(j == m){
			pos[top++] = i - m;
			j = 0;
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



