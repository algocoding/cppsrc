#include <iostream>
#include <stdio.h>
const int MAXV = 100;
int V, E; 	                // ���(����)��, ������
int P[MAXV + 1], L[MAXV + 1], R[MAXV + 1];
                            // �θ�, ����, ������
int v1 = 12, v2 = 13;       // ������ �� ���

int findLCA( )
{
    bool visit[MAXV + 1];

    int v = v1;
    while(v){
    	visit[v] = true;
    	v = P[v];
    }
    v = v2;
    while(v){
    	if(visit[v]) return v;
       	v = P[v];
    }
    return 0;
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
	printf("lca = %d\n", findLCA() );
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
