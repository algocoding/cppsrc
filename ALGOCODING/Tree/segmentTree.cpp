/*
 * segmentTree.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */

#include <iostream>
#include <cstring>
using namespace std;
const int N = 8;
int arr[N] = {3, 9, 4, 2, 7, 8, 10, 1};
int * tree;		// ���� Ʈ��
int * lazy;
// ���� Ʈ�� �����ϱ�
int makeTree(int l, int r, int idx)
{
	if(l == r) return tree[idx] = arr[l];

	int mid = (l + r) / 2;

	int sum = makeTree(l, mid, idx * 2);	// ���� �ڽ�
	sum += makeTree(mid + 1, r, idx * 2 + 1);

	return tree[idx] = sum;
}
// ����[a, b] ��
int query(int l, int r, int idx, int a, int b)
{
	// ��� ����[left, right]�� [a, b]�� ���� ��ġ�� �ʴ� ���
	if(b < l || a > r) return 0;

	// ��� ����[left, right]�� [a, b] ������ ��� ���ԵǴ� ���
	if(a <= l && r <= b) return tree[idx];

	// �� ���� ���
	int mid = (l + r) / 2;
	int lsum = query(l, mid, idx * 2, a, b);
	int rsum = query(mid + 1, r, idx * 2 + 1, a, b);

	return lsum + rsum;
}

// �����ϱ� arr[p]�� +val �ϱ�
int updatePoint(int l, int r, int idx, int p, int val)
{
	if(p < l || p > r) return tree[idx];

	tree[idx] += val;

	if(l != r)
	{
		int mid = (l + r) / 2;
		int lsum = updatePoint(l, mid, idx * 2, p, val);
		int rsum = updatePoint(mid + 1, r, idx * 2 + 1, p, val);
		tree[idx] = lsum + rsum;
	}
	return tree[idx];
}
void propagation(int left, int right, int idx)
{
	tree[idx] += lazy[idx] * (right - left + 1);
	if (left != right){
		lazy[idx * 2] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}
int queryLazy(int l, int r, int idx, int a, int b)
{
	if (lazy[idx] != 0)
	{
		propagation(idx, l, r);
	}
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[idx];

	int mid = (l + r) / 2;
	return queryLazy(l, mid, idx*2, a, b) + queryLazy(mid + 1, r, idx*2 + 1, a, b);
}
// ���� ���� [a, b]�� +val �ϱ�
void updateRange(int l, int r, int idx, int a, int b, int val)
{
	if (lazy[idx] != 0) return;

	if (l > b || a > r) return;
	if (a <= l && r <= b)
	{
		tree[idx] += val*(r - l + 1);
		if (l != r)
		{
			lazy[idx * 2] += val;
			lazy[idx * 2 + 1] += val;
		}
		return;
	}
	int mid = (l + r) / 2, left = idx * 2, right = left + 1;
	updateRange(l, mid, idx * 2, a, b, val);
	updateRange(mid + 1, r, idx * 2 + 1, a, b, val);
	tree[idx] = tree[left] + tree[right];
}

int main()
{
	int h = 0;	// ����
	for(int n = N - 1; n; h++)
		n >>= 1;
	tree = new int[1 << (h + 1)];
	lazy = new int[1 << (h + 1)];
	memset(tree, 0, sizeof(int)*(1 << (h + 1)));
	memset(lazy, 0, sizeof(int)*(1 << (h + 1)));

	makeTree(0, N - 1, 1); // ���� idx, �� idx, tree�� ��Ʈ ��ȣ

	printf("������(%d, %d) = %d\n", 2, 6, query(0, N - 1, 1, 2, 6));
	printf("���� (%d, %d) = %d\n", 5, -3, updatePoint(0, N - 1, 1, 5, -3));
	for(int i = 1; i < (1 << (h + 1)); i++)
		printf("%2d|", i);
	printf("\n---------------------------------------------\n");
	for(int i = 1; i < (1 << (h + 1)); i++)
		printf("%2d|", tree[i]);
	cout << endl;


	delete[] tree;
	delete[] lazy;
	return 0;
}



