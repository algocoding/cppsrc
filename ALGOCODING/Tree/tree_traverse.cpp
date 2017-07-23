/*********************************************************
	author: JongYun, Jung
	e-mail: algocoding.net_at_gmail.com
	--> ����Ʈ�� ���� ��ȸ(���)
*********************************************************/
#include <iostream>
using namespace std;

int V, E;                   // ����, ������
int L[100], R[100], P[100]; // ����, ������, �θ�
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
