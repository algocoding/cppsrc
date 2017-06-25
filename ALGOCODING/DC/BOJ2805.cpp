/*
* 나무자르기.cpp https://www.acmicpc.net/problem/2805
*
*  Created on: 2017. 6. 25.
*      Author: JongYun
*/


#include <stdio.h>

const int MAXN = 1000000;
const int MAXM = 2000000000;
int N, M;
int tree[MAXN + 1];
int max;

int main()
{
	long long lo = 0, hi;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tree[i]);
		if (tree[i] > hi) hi = tree[i];
	}

	while (lo <= hi)
	{
		long long mid = (lo + hi) / 2;

		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid) sum += (tree[i] - mid);
		}
		if (sum >= M) {
			max = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	printf("%d\n", max);
	return 0;
}

