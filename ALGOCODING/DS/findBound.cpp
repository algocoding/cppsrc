/*
 * findBound.cpp
 *
 *  Created on: 2017. 8. 8.
 *      Author: JongYun
 */

#include <cstdio>
#include <algorithm>
using namespace std;

int lowBound(int arr[], int lo, int hi, int key)
{
	if(lo > hi) return hi;
	int mid =  (lo + hi) / 2;
	if(key <= arr[mid])
		return lowBound(arr, lo, mid - 1, key);
	else
		return lowBound(arr, mid + 1, hi, key);
}
int upBound(int arr[], int lo, int hi, int key)
{
	if(lo > hi) return lo;
	int mid =  (lo + hi) / 2;
	if(key >= arr[mid])
		return upBound(arr, mid + 1, hi, key);
	else
		return upBound(arr,lo, mid - 1, key);
}
int main()
{
	int arr[] = { 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 7, 7, 7, 8, 8, 8, 8, 9, 9, 10};
	int n = sizeof(arr) / 4;
	printf("ÀÚ·á¼ö = %d\n", n);
	int lo = lowBound(arr, 0, n - 1, 0);
	int hi = upBound(arr, 0, n - 1, 0);
	printf("lo = %d, hi = %d\n", lo, hi);
	return 0;
}
