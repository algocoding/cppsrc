/*
 * counting1.cpp
 *
 *  Created on: 2017. 6. 27.
 *      Author: JongYun
 */

// �ε��� ���� ��Ű�鼭 �ű��


#include <stdio.h>
const int MAX = 4;	// �ִ밪
const int N = 10;
int unsorted[N] = {1, 4, 0, 2, 1, 4, 2, 0, 1, 4};
int count[MAX + 1];	// �ڷᰪ�� ������ 0 ���� �ִ밪
int sorted[N];	// ���ĵ� �ڷ� ����


void countingSort(int n, int k)
{
	for(int i = 0; i <= k; i++)
		count[i] = 0;

	for(int i = 0; i < n; i++)
		count[unsorted[i]]++;

	for(int i = 1; i < n; i++)
		count[i] += count[i - 1];

	for(int i = n - 1; i >= 0; i--)
	{
		count[unsorted[i]]--;
		sorted[count[unsorted[i]]] = unsorted[i];
	}
}

int main()
{
	countingSort(N, MAX);

	for(int i = 0; i < N; i++)
		printf("%d ", sorted[i]);
	printf("\n");
	return 0;
}
