/*
 * BOJ11004.cpp
 *
 *  Created on: 2017. 8. 8.
 *      Author: JongYun
 */

#include  <cstdio>
const int MAXN = 5000000;
int arr[MAXN + 10];
int medians[MAXN/5];
inline void swap(int & a, int & b){ int t = a; a = b; b = t; }
int find_kth(int arr[], int n, int k)
{ // arr: 배열, n: 원소수, k: k번째(실제, k - 1)

	if (n == 1 && k == 0) return arr[0];

	//  1. 원소수 n인 배열을 원소수가 5인 (n / 5)개 그룹으로 나눈다.
	//     n이 5의 배수가 아니면 마지막 그룹의 원소는 (n % 5)개가 된다.
	int m = (n + 4) / 5;

	// 2. 각 그룹의 중앙값을 찾는다. 삽입(선택) 정렬을 수행하고 중앙값을 취한다.
	for (int i = 0; i < m; i++)
	{
		if (5 * i + 4 < n) {

			int * part = arr + 5 * i;

			for (int j0 = 0; j0 < 3; j0++)
			{
				int jmin = j0;
				for (int j = j0 + 1; j < 5; j++) {
					if (part[j] < part[jmin])
						jmin = j;
				}
				swap(part[j0], part[jmin]);
			}
			medians[i] = part[2];
		}
		else {
			medians[i] = arr[5 * i];
		}
	}
	// 3. 재귀적으로 (n / 5) 개의 중앙값들에 대해서 중앙값 x 를 찾는다.
	int pivot = find_kth(medians, m, m / 2);

	for (int i = 0; i < n; i++) {
		if (arr[i] == pivot) {
			swap(arr[i], arr[n - 1]);
			break;
		}
	}
	// 4. 분할(Partition) 알고리즘을 사용해서 중앙값 x를 기준으로 분할한다.
	int store = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[store++]);
		}
	}
	swap(arr[store], arr[n - 1]);

	/* 5. i = k 이면 x를 반환한다.
	       i < k 면 왼쪽에서 i번째 원소를 찾고
	       i > k 면 오른쪽에서 i - k 번째 원소를 찾는다.
	*/
	if (store == k) {
		return pivot;
	}
	else if (store > k) {
		return find_kth(arr, store, k);
	}
	else {
		return find_kth(arr + store + 1, n - store - 1, k - store - 1);
	}
}
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", find_kth(arr, N, K - 1));
	return 0;
}


