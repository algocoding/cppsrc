/*
 * BOJ7453.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */

// 4���� �迭, �迭�� ũ��� 1<= N <= 4,000

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 4000;
int N;
int arr[4][MAXN];
int AB[MAXN * MAXN];
int sorted[MAXN * MAXN];
int CD[MAXN * MAXN];

inline void swap(int & a, int & b){ int t = a; a = b; b = t;}
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
int lowBound(int arr[], int lo, int hi, int key)
{
	while(lo <= hi)
	{
		int mid =  (lo + hi) / 2;
		if(key <= arr[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return hi;
}
int upBound(int arr[], int lo, int hi, int key)
{
	while(lo <= hi)
	{
		int mid =  (lo + hi) / 2;
		if(key >= arr[mid])
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return lo;
}
int main()
{
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d%d%d%d", &arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			AB[i * N + j] = arr[0][i] + arr[1][j];
			CD[i * N + j] = arr[2][i] + arr[3][j];
		}
	}
	mergeSort(CD, 0, N * N - 1);

	long long cnt = 0;

	for(int i = 0; i < N * N; i++)
	{
		int lo = lowBound(sorted, 0, N * N - 1, -AB[i]);
		int hi = upBound(sorted, 0, N * N - 1, -AB[i]);
		cnt += hi - lo - 1;
	}
	printf("%lld\n", cnt);
	return 0;
}
