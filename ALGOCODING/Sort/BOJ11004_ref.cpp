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
{ // arr: �迭, n: ���Ҽ�, k: k��°(����, k - 1)

	if (n == 1 && k == 0) return arr[0];

	//  1. ���Ҽ� n�� �迭�� ���Ҽ��� 5�� (n / 5)�� �׷����� ������.
	//     n�� 5�� ����� �ƴϸ� ������ �׷��� ���Ҵ� (n % 5)���� �ȴ�.
	int m = (n + 4) / 5;

	// 2. �� �׷��� �߾Ӱ��� ã�´�. ����(����) ������ �����ϰ� �߾Ӱ��� ���Ѵ�.
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
	// 3. ��������� (n / 5) ���� �߾Ӱ��鿡 ���ؼ� �߾Ӱ� x �� ã�´�.
	int pivot = find_kth(medians, m, m / 2);

	for (int i = 0; i < n; i++) {
		if (arr[i] == pivot) {
			swap(arr[i], arr[n - 1]);
			break;
		}
	}
	// 4. ����(Partition) �˰����� ����ؼ� �߾Ӱ� x�� �������� �����Ѵ�.
	int store = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[store++]);
		}
	}
	swap(arr[store], arr[n - 1]);

	/* 5. i = k �̸� x�� ��ȯ�Ѵ�.
	       i < k �� ���ʿ��� i��° ���Ҹ� ã��
	       i > k �� �����ʿ��� i - k ��° ���Ҹ� ã�´�.
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


