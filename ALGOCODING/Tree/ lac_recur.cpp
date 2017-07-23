/*
 *  lac_recur.cpp
 *
 *  Created on: 2017. 7. 23.
 *      Author: JongYun
 */
#include <iostream>
#include <stdio.h>
const int MAXV = 100;
int V, E; 	                // ���(����)��, ������
int P[MAXV + 1], L[MAXV + 1], R[MAXV + 1];
                            // �θ�, ����, ������
int v1 = 12, v2 = 13;       // ������ �� ���

int findLCA(int v)			// v: ���� �湮 ���
{
    if(v == 0) return 0;
    if(v == v1 || v == v2) return v;

    int l = findLCA(L[v]);   // ���� �ڽ� Ʈ���� ����?
    int r = findLCA(R[v]);   // ������ �ڽ� Ʈ���� ����?

    if( l && r ) return v;  // ���ʿ� �� �ִ� ���

    return l ? l : r;       // ���ʸ� �ְų� ���� ���
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

// 13: ����, 12: ������
// 12���� ���� ������
 *
 */
