/*
 * ford_fulkerson.cpp
 *
 *  Created on: 2017. 8. 14.
 *      Author: JongYun
 */

#include <stdio.h>
#define V 6
int Q[100];
int front, rear;
int P[100];

bool bfs(int rGraph[V][V], int s, int t)
{
	bool visited[V] = { false, };

	front = rear = -1;
	Q[++rear] = s;
	visited[s] = true;
	P[s] = -1;

	while (front != rear)
	{
		int u = Q[++front];

		for (int v = 0; v < V; v++)
		{
			if (visited[v] == false && rGraph[u][v] > 0)
			{
				Q[++rear] = v;
				P[v] = u;
				visited[v] = true;
			}
		}
	}
	// �������� �����ߴ��� ���θ� ��ȯ
	return (visited[t] == true);
}

inline int MIN(int a, int b){
	return a > b ? b : a;
}
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;
	int rGraph[V][V]; // �ܿ� ��Ʈ��ũ

	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V];  // �ִ� ��� Ʈ�� ����

	int max_flow = 0;  // �ִ� �÷ο� ����

	while (bfs(rGraph, s, t)) // Ȯ�� ��� ã��
	{
		// Ȯ�� ��ο��� �ܿ� �뷮 ã��.
		int path_flow = 0xffffff;
		for (v = t; v != s; v = parent[v])
		{
			u = P[v];
			path_flow = MIN(path_flow, rGraph[u][v]);
		}

		// Ȯ�� ��θ� Ȯ���ϱ�
		for (v = t; v != s; v = parent[v])
		{
			u = P[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
	int graph[V][V] = { { 0, 16, 13, 0, 0, 0 },
	{ 0, 0, 10, 12, 0, 0 },
	{ 0, 4, 0, 0, 14, 0 },
	{ 0, 0, 9, 0, 0, 20 },
	{ 0, 0, 0, 7, 0, 4 },
	{ 0, 0, 0, 0, 0, 0 }
	};
	printf("�ִ� �÷ο� = %d\n", fordFulkerson(graph, 0, 5));

	return 0;
}
