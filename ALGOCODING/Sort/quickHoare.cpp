/*********************************************************
author: JongYun, Jung
e-mail: algocoding.net@gmail.com
--> QuickSort(Hoare-partition)
*********************************************************/
#include <cstdio>

void print_arr(int arr[], int size){
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}
inline void swap(int & a, int & b)
{
	int t = a; a = b; b = t;
}
void quick_hoare(int arr[], int lo, int hi)
{
	if (lo < hi)
	{
		int i = lo;
		int j = hi;
		while (i < j)
		{
			while (i <= hi && arr[lo] >= arr[i]) i++;
			while (arr[lo] < arr[j]) j--;

			if (i < j){
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[lo], arr[j]);

		quick_hoare(arr, lo, j - 1);
		quick_hoare(arr, j + 1, hi);
	}
}
int main()
{
	puts("QuickSort by Hoare-Partition >>");
	int arr[] = { 23, 45, 2, 5, 88, 12, 7, 49, 45, 16 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, size);
	quick_hoare(arr, 0, size - 1);
	print_arr(arr, size);
	return 0;
}


