/*********************************************************
	author: JongYun, Jung
	e-mail: algocoding.net_at_gmail.com
	--> 이진트리 중위 순회(재귀)
*********************************************************/
#include <iostream>
using namespace std;

int V, E;                   // 노드수, 간선수
int L[100], R[100], P[100]; // 왼쪽, 오른쪽, 부모
void inorder(int v)
{

    if (v == 0) return;

    inorder(L[v]);
    printf("%d ", v);
    inorder(R[v]);
}
int main()
{
    int from, to;

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to;

        if (!L[from]) L[from] = to;
        else R[from] = to;
        P[to] = from;
    }
    inorder(1);
}
