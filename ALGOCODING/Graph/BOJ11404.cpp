/*
 * BOJ11404.cpp
 * 경로 찾기 https://www.acmicpc.net/problem/11403
 *  Created on: 2017. 8. 16.
 *      Author: JongYun
 */
#include <cstdio>
using namespace std;
const int MAXN = 100;
int D[MAXN + 1][MAXN + 1];

int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &D[i][j]);

	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			if(i == k) continue;

			for(int j = 0; j < N; j++)
			{
				if(j == k) continue;
				D[i][j] = D[i][j] || (D[i][k] && D[k][j]);
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	return 0;
}
