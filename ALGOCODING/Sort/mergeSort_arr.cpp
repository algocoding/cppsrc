/*
 * mergeSort.cpp
 *
 *  Created on: 2017. 8. 14.
 *      Author: JongYun
 */
#include <stdio.h>
void mergeSort(int arr[], int sorted[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(arr, sorted, l, mid);
		mergeSort(arr, sorted, mid + 1, r);

		int i = l, j = mid + 1, k = l, t;

		while (i <= mid && j <= r)
		{
			if (arr[i] < arr[j]) sorted[k++] = arr[i++];
			else sorted[k++] = arr[j++];
		}
		if (i <= mid)
			for (t = i; t <= mid; t++, k++)
				sorted[k] = arr[t];
		else
			for (t = j; t <= r; t++, k++)
				sorted[k] = arr[t];

		for (t = l; t <= r; t++)
			arr[t] = sorted[t];
	}
}

int arr[] = { 82, 13, 22, 61, 12, 52, 41, 75, 98 };
int sorted[100];

int main()
{
	int size = sizeof(arr)/4;
	for (int i = 0; i < size; i++) printf("%3d ", arr[i]);
	printf("\n");

	mergeSort(arr, sorted, 0, size - 1);

	for (int i = 0; i < size; i++) printf("%3d ", arr[i]);
	printf("\n");

	return 0;
}

