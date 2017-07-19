/*
 * BOJ2589.cpp
 * º¸¹°¼¶ https://www.acmicpc.net/problem/2589
 *  Created on: 2017. 7. 19.
 *      Author: JongYun
 */
#include <iostream>
#include <stdio.h>

const int MAX = 50;
char MAP[MAX + 2][MAX + 2];
int D[MAX + 2][MAX + 2];
int visit[MAX + 2][MAX + 2];
int N, M;

int xarr[MAX * MAX], yarr[MAX * MAX];
int front, rear;

int main()
{
	//freopen("output.txt", "w", stdout);
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int sol = 0, time;
	scanf("%d%d", &N, &M);

	for(int i = 0; i < N; i++)
		scanf(" %s", MAP[i]);

	for(int i = 0; i < N; i++)
	for(int j = 0; j < M; j++)
	{

		if(MAP[i][j] == 'L')
		{
			time = 0;
			front = rear = -1;

			++rear; xarr[rear] = i; yarr[rear] = j;
			D[i][j] = 0;
			visit[i][j] = 1;
			while(front != rear)
			{
				++front;
				int x = xarr[front];
				int y = yarr[front];

				for(int k = 0; k < 4; k++)
				{
					int tx = x + dx[k]; int ty = y + dy[k];
					if(tx < 0 || tx == N || ty < 0 || ty == M) continue;
					if(MAP[tx][ty] == 'W' || visit[tx][ty] == 1) continue;

					D[tx][ty] = D[x][y] + 1; visit[tx][ty] = 1;

					++rear; xarr[rear] = tx; yarr[rear] = ty;

					if(D[tx][ty] > time) time = D[tx][ty];
				}
			}
			if(sol < time) sol = time;
			for(int x = 0; x < N; x++)
			{
				for(int y = 0; y < M; y++)
				{
					//printf("%2d", D[x][y]);
					visit[x][y] = 0;
				}
				//printf("\n");
			}
			//printf("---------------------------------\n");
//			for(int k = 0; k <= rear; k++)
//				D[xarr[k]][yarr[k]] = visit[xarr[k]][yarr[k]] = 0;
		}
	}
	printf("%d\n", sol);

	return 0;
}


