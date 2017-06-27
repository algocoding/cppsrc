/*
 * counting2.cpp
 *
 *  Created on: 2017. 6. 27.
 *      Author: JongYun
 */


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

	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int prev = count[i];
		count[i] = sum;
		sum += prev;
	}

	for(int i = 0; i < n; i++)
	{
		sorted[count[unsorted[i]]] = unsorted[i];
		count[unsorted[i]]++;
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



