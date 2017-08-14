/*
* BOJ11004.cpp - https://www.acmicpc.net/problem/11004
*  Created on: 2017. 8. 8.
*      Author: JongYun
*/
#include  <cstdio>
const int MAXN = 5000000;
int arr[MAXN + 10];
inline void swap(int & a, int & b){ int t = a; a = b; b = t; }

// ũ�� 5�� �迭�� �����ؼ� �߾Ӱ� ���ϱ�
int find_median(int arr[], int n)
{
	if (n == 1) return arr[0];

	int ndiv = (n + 4) / 5;
	int * median = new int[ndiv];

	for (int i = 0; i < ndiv; i++)
	{
		int * part = arr + i * 5; // 5�� �迭 ���� �ּ� ����
		if ( i != ndiv - 1)
		{
			for (int j = 0; j < 4; j++) // ���� ����
			{
				int min = j;
				for (int k = j + 1; k < 5; k++)
					if (part[min] > part[k]) min = k;
				swap(part[j], part[min]);
			}
			median[i] = part[2];
		}else{					// ������ �׷�
			//int rem = n - i * 5;// ���� ��
			//for (int j = 0; j < rem - 1; j++)
			//{
			//	int min = j;
			//	for (int k = j + 1; k < rem; k++)
			//		if (part[min] > part[k]) min = k;
			//	swap(part[j], part[min]);
			//}
			median[i] = part[0];
		}
	}

	int ret = find_median(median, ndiv);

	delete[] median;

	return ret;
}
int find_kth(int arr[], int n, int k)
{ // arr: �迭, n: ���Ҽ�, k: k��°(����, k - 1)

	int median = find_median(arr, n);

	// �߾Ӱ��� ��ġ ã��
	int pos;
	for (pos = 0; pos < n; pos++)
		if (arr[pos] == median) break;

	// �߾Ӱ��� ������ ���ҿ� ��ȯ
	swap(arr[pos], arr[n - 1]);

	// Lomuto-Partition �����ϱ�

	int i = -1, j;
	for (j = 0; j < n; j++)
	{
		if (arr[j] < arr[n - 1])
			swap(arr[++i], arr[j]);
	}
	swap(arr[++i], arr[n - 1]);

	if (i == k)
		return arr[i];
	else if (i > k)
		return find_kth(arr, i, k);
	else
		return find_kth(arr + i + 1, n - i - 1, k - i - 1);
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


