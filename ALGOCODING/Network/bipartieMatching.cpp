/*
 * bipartieMatching.cpp
 * 이분 매칭 => 축사 배정
 *  Created on: 2017. 8. 14.
 *      Author: JongYun
 */
#include <stdio.h>
const int MAXN = 200;
const int MAXM = 200;

int E[MAXN + 1];
int G[MAXN + 1][MAXM + 1];
int match[MAXN + 1];
bool visited[MAXN + 1];
int dfs(int a)
{
	if (visited[a]) return 0;

	visited[a] = true;

	for (int i = 0; i < E[a]; i++)
	{
		int b = G[a][i];
		if (match[b] == -1 || dfs(match[b]))
		{
			match[b] = a;
			return 1;
		}
	}
	return 0;
}
int main()
{
	//freopen("이분매칭.txt", "r", stdin);
	int N, M;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)	E[i] = 0;
	for (int i = 0; i <= M; i++) match[i] = -1;


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &E[i]);
		for (int j = 0; j < E[i]; j++)
			scanf("%d", &G[i][j]);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N; j++) visited[j] = false;
		cnt += dfs(i);

	}
	printf("%d\n", cnt);
	return 0;
}



