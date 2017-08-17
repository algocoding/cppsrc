/*
* BOJ2206.cpp
* 벽 부수고 이동하기 https://www.acmicpc.net/problem/2206
*  Created on: 2017. 8. 16.
*      Author: JongYun
*/

#include <cstdio>
using namespace std;
const int MAXN = 1000;
int MAP[MAXN + 1][MAXN + 1];
int visit[MAXN + 1][MAXN + 1];
int D[MAXN + 1][MAXN + 1];
typedef struct _node{
	int x, y;
	int wall;	// 1: 벽 통과 안함, 2: 벽 통과함
}NODE;
NODE Q[MAXN * MAXN];
int front, rear;
int N, M;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &MAP[i][j]);

	front = rear = -1;

	NODE cur = { 1, 1, 1 };	// 시작점
	Q[++rear] = cur;
	visit[1][1] = 1;
	D[1][1] = 1;

	while (front != rear)
	{
		cur = Q[++front];

		if (cur.x == N && cur.y == M) break;

		for (int i = 0; i < 4; i++)
		{
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			if (x < 1 || x > N || y < 1 || y > M) continue;

			if(MAP[x][y] == 0)			// 0 => 길
			{
				NODE tmp = { x, y, cur.wall };
				if(visit[x][y] == 0)	// 방문하지 않은 경우
				{
					Q[++rear] = tmp;
					D[x][y] = D[cur.x][cur.y] + 1;
					visit[x][y] = cur.wall;
				}else if(visit[x][y] == 2 && cur.wall == 1) // (x,y)가 벽을 부수고 방문했던 곳
				{											// 벽을 부수지 않고 왔으면 탐색 진행
					Q[++rear] = tmp;
					D[x][y] = D[cur.x][cur.y] + 1;
					visit[x][y] = 1;
				}
			}
			else if (MAP[x][y] == 1)	// 1 => 벽
			{
				if(cur.wall == 1 && visit[x][y] == 0) // (x,y)가 미방문이고 벽을 부수고 오지 않음.
				{
					NODE tmp = { x, y, 2 };
					Q[++rear] = tmp;
					D[x][y] = D[cur.x][cur.y] + 1;
					visit[x][y] = 2;
				}
			}
		}
	}
	if(D[N][M])
		printf("%d\n", D[N][M]);
	else
		printf("-1\n");
	return 0;
}

