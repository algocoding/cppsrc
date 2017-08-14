/*
 * quickLomuto.cpp
 *
 *  Created on: 2017. 8. 14.
 *      Author: JongYun
 */


#include <cstdio>

void print_arr(int arr[], int size){
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}
inline void swap(int & a, int & b)
{
	int t = a; a = b; b = t;
}
void quick_lomuto(int arr[], int lo, int hi)
{
	if (lo < hi)
	{
		int i = lo - 1, j;

		for(j = lo; j < hi; j++)
		{
			if(arr[j] < arr[hi])
				swap(arr[++i], arr[j]);
		}
		swap(arr[++i], arr[hi]);

		quick_lomuto(arr, lo, i - 1);
		quick_lomuto(arr, i + 1, hi);
	}
}
int main()
{
	puts("QuickSort by Lomuto-Partition >>");
	int arr[] = { 23, 45, 2, 5, 88, 12, 7, 49, 45, 16 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, size);
	quick_lomuto(arr, 0, size - 1);
	print_arr(arr, size);
	return 0;
}

