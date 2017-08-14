/*
 * BOJ10816.cpp
 *
 *  Created on: 2017. 8. 10.
 *      Author: JongYun
 */
#include <cstdio>
const int MAXN = 500000;
int arr[MAXN + 1];
int sorted[MAXN + 1];
inline void swap(int & a, int & b){ int t = a; a = b; b = t; }
int lower_bound(int key, int lo, int hi)
{
    while(lo < hi)
    {
        int mid = (lo + hi) / 2; // �߰� ��ġ

        if (key > arr[mid])      // �����ʿ��� Ž��
            lo = mid + 1;
        else                     // key <= arr[mid]
            hi = mid;            // ���ʿ��� Ž��
    }
    return lo;
}

int upper_bound(int key, int lo, int hi)
{
    while(lo < hi)
    {
        int mid = (lo + hi) / 2; // �߰� ��ġ

        if (key > arr[mid])      // �����ʿ��� Ž��
            lo = mid;
        else                     // key <= arr[mid]
            hi = mid + 1;        // �����ʿ��� Ž��
    }
    return lo;
}
void quickSort(int lo, int hi)
{
	if(lo < hi)
	{
		int i = lo - 1, j;
		for(j = lo; j < hi; j++)
		{
			if(arr[j] < arr[hi])
				swap(arr[++i], arr[j]);
		}
		swap(arr[++i], arr[hi]);

		quickSort(lo, i - 1);
		quickSort(i + 1, hi);
	}
}
void merge(int arr[], int l, int mid, int r)
{
	int i, j, k, t;
	i = l; 		// ù ��° �κ������� ���� ��ġ ����
	j = mid + 1; 	// �� ��° �κ������� ���� ��ġ ����
	k = l; 		// �迭 sorted�� ���ĵ� ���Ҹ� ������ ��ġ ����

	while (i <= mid && j <= r){
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}

	if (i > mid)
		for (t = j; t <= r; t++, k++)
			sorted[k] = arr[t];
	else
		for (t = i; t <= mid; t++, k++)
			sorted[k] = arr[t];

	for (t = l; t <= r; t++)
		arr[t] = sorted[t];
}

void mergeSort(int arr[], int l, int r)
{
	int mid;
	if (l < r){
		mid = (l + r) / 2;
		mergeSort(arr, l, mid); 	// �� �κп� ���� ���� �۾� ����
		mergeSort(arr, mid + 1, r); 	// �� �κп� ���� ���� �۾� ����
		merge(arr, l, mid, r); 	// �κ����տ� ���Ͽ� ���İ� ���� �۾� ����
	}
}
int main()
{
	printf("start......\n");
	int N, M;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	quickSort(0, N - 1);

	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		int key;
		scanf("%d", &key);

		int lo = lower_bound(key, 0, N);
		int hi = upper_bound(key, 0, N);

		printf("%d ", hi - lo);
	}
	return 0;
}
