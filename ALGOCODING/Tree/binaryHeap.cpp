/*
 * binaryHeap.cpp
 *
 *  Created on: 2017. 6. 29.
 *      Author: JongYun
 */

#include <stdio.h>
const int MAXN = 100;
int heap[MAXN];	// 힙 저장소
int hsize;		// 힙 크기, 마지막 자료 위치
inline void swap(int & a, int & b){
	int t = a; a = b; b = t;
}
bool put(int item)
{
	if(hsize == MAXN - 1) return false;

	heap[++hsize] = item;

	int c = hsize, p = c/2;

	while(p)
	{
		if(heap[p] > heap[c])
		{
			swap(heap[p], heap[c]);
			c = p; p = c/2;
		}else break;
	}
	return true;
}
bool get(int & ret)
{
	ret = -1;
	if(hsize == 0) return false;

	ret = heap[1];
	heap[1] = heap[hsize--];

	int p = 1, c = 2;

	while(c <= hsize)
	{
		if( (c+1 <= hsize) && heap[c] > heap[c+1])
			c++;

		if(heap[p] > heap[c])
		{
			swap(heap[p], heap[c]);
			p = c;
			c = p*2;
		}else break;
	}
	return true;
}

int main()
{
	int arr[] = {7, 45, 2, 12, 23, 16, 4, 88, 49, 5};
	for(int i = 0; i < 10; i++)
		put(arr[i]);

	int ret;

	while(get(ret))
		printf("%d ", ret);
	return 0;
}



