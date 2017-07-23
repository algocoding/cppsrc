/*
 *  lac_recur.cpp
 *
 *  Created on: 2017. 7. 23.
 *      Author: JongYun
 */
#include <iostream>
#include <stdio.h>
const int MAXV = 100;
int V, E; 	                // 노드(정점)수, 간선수
int P[MAXV + 1], L[MAXV + 1], R[MAXV + 1];
                            // 부모, 왼쪽, 오른쪽
int v1 = 12, v2 = 13;       // 임의의 두 노드

int findLCA(int v)			// v: 현재 방문 노드
{
    if(v == 0) return 0;
    if(v == v1 || v == v2) return v;

    int l = findLCA(L[v]);   // 왼쪽 자식 트리에 존재?
    int r = findLCA(R[v]);   // 오른족 자식 트리에 존재?

    if( l && r ) return v;  // 양쪽에 다 있는 경우

    return l ? l : r;       // 한쪽만 있거나 없는 경우
}
int main(){
	freopen("tree_input.txt", "r", stdin);
	scanf("%d%d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(L[u]) R[u] = v;
		else L[u] = v;
		P[v] = u;
	}
	printf("lca = %d\n", findLCA(1) );
	return 0;
}

/*
 *
13 12
1 2 1 3 2 4 2 5 3 6 3 7 4 8 5 9 6 10 6 11 7 12 10 13

// 13: 노드수, 12: 간선수
// 12개의 간선 정보들
 *
 */
