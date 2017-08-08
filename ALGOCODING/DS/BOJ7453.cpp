/*
 * BOJ7453.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */

// 4개의 배열, 배열의 크기는 1<= N <= 4,000

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 4000;
int N;
int arr[4][MAXN];
//int AB[MAXN * MAXN];
//int CD[MAXN * MAXN];
vector<int> AB, CD;
inline void swap(int & a, int & b){ int t = a; a = b; b = t;}
void quickSort(int arr[], int lo, int hi)
{
	if(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(arr[hi] >= arr[mid] && arr[mid] >= arr[lo])
			swap(arr[hi], arr[mid]);
		else if(arr[lo] >= arr[mid] && arr[mid] >= arr[hi])
			swap(arr[hi], arr[mid]);
		else if(arr[hi] >= arr[lo] && arr[lo] >= arr[mid])
			swap(arr[hi], arr[lo]);
		else if(arr[mid] >= arr[lo] && arr[lo] >= arr[hi])
			swap(arr[hi], arr[lo]);

		int i = lo - 1, j;
		for(j = lo; j < hi; j++)
		{
			if(arr[hi] > arr[j])
				swap(arr[++i], arr[j]);
		}
		swap(arr[++i], arr[hi]);
		quickSort(arr, lo, i - 1);
		quickSort(arr, i + 1, hi);
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
			AB.push_back(arr[0][i] + arr[1][j]);
			CD.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(CD.begin(), CD.end());

	long long cnt = 0;
	vector<int>::iterator lo, hi;
	for(int i = 0; i < AB.size(); i++)
	{
		lo = lower_bound(CD.begin(), CD.end(), -AB[i]);
		hi = upper_bound(CD.begin(), CD.end(), -AB[i]);
		cnt += hi - lo;
	}
	printf("%lld\n", cnt);
	return 0;
}
