/*
 * BOJ11724_dfs.cpp
 *
 * 연결 요소의 개수 https://www.acmicpc.net/problem/11724
 * Created on: 2017. 8. 16.
 *      Author: JongYun
 */

#include <cstdio>
using namespace std;
const int MAXN = 1000;
int G[MAXN + 1][MAXN + 1];
int top[MAXN + 1];
int cid[MAXN + 1];
int N, M, id;

void DFS(int v)
{
	cid[v] = id;
	for(int i = 0; i < top[v]; i++)
	{
		if(cid[G[v][i]] == 0)
			DFS(G[v][i]);
	}
}
int main()
{
	scanf("%d%d", &N, &M);

	for(int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][top[u]++] = v;
		G[v][top[v]++] = u;
	}
	id = 0;
	for(int i = 1; i <= N; i++)
	{
		if(cid[i] == 0)
		{
			++id; DFS(i);
		}
	}
	printf("%d\n", id);
	return 0;
}

