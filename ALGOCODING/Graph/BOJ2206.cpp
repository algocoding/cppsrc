/*
* BOJ2206.cpp
* �� �μ��� �̵��ϱ� https://www.acmicpc.net/problem/2206
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
	int wall;	// 1: �� ��� ����, 2: �� �����
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

	NODE cur = { 1, 1, 1 };	// ������
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

			if(MAP[x][y] == 0)			// 0 => ��
			{
				NODE tmp = { x, y, cur.wall };
				if(visit[x][y] == 0)	// �湮���� ���� ���
				{
					Q[++rear] = tmp;
					D[x][y] = D[cur.x][cur.y] + 1;
					visit[x][y] = cur.wall;
				}else if(visit[x][y] == 2 && cur.wall == 1) // (x,y)�� ���� �μ��� �湮�ߴ� ��
				{											// ���� �μ��� �ʰ� ������ Ž�� ����
					Q[++rear] = tmp;
					D[x][y] = D[cur.x][cur.y] + 1;
					visit[x][y] = 1;
				}
			}
			else if (MAP[x][y] == 1)	// 1 => ��
			{
				if(cur.wall == 1 && visit[x][y] == 0) // (x,y)�� �̹湮�̰� ���� �μ��� ���� ����.
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

