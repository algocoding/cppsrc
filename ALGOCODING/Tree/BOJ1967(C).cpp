/*
 * 트리의 지름(https://www.acmicpc.net/problem/1967)
 * 이진트리라 가정하고 작성
 *  Created on: 2017. 7. 23.
 *      Author: JongYun
 */

#include <iostream>
#include <stdio.h>


const int MAXN = 10000;	// 노드 번호는 1..10000, 루트는 항상 1
int V;
int L[MAXN + 1][2], R[MAXN + 1][2];
int radius;

int postorder(int v)
{
	if(v == 0) return 0;

	int l = postorder(L[v][0]) + L[v][1];
	int r = postorder(R[v][0]) + R[v][1];
	int tmp = l + r;
	radius = radius < tmp ? tmp : radius;
	return l > r ? l: r;
}
int main()
{
	scanf("%d", &V);
	for(int i = 0; i < V - 1; i++)
	{
		int p, v, w;
		scanf("%d%d%d", &p, &v, &w);
		if(L[p][0]) {
			R[p][0] = v; R[p][1] = w;
		}else{
			L[p][0] = v; L[p][1] = w;
		}
	}
	postorder(1);
	printf("%d\n", radius);
}

