/*
 * fenwick.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */
//int arr[17] = {0, 1, 0, 2, 11, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2};
#include <iostream>
#include <cstring>
using namespace std;

const int N = 8;
int arr[N + 1] = {0, 3, 9, 4, 2, 7, 8, 10, 1};
int fw[N + 1];

inline int LSB(int x){	return x & -x; }

void updatePoint(int p, int v)
{
	for( ;p <= N; p += LSB(p))
		fw[p] += v;
}
void updateRange()
{

}
// 구간합 [1, a]
int query(int a)
{
	int sum = 0;
	for( ;a > 0; a -= LSB(a))
		sum += fw[a];
	return sum;
}
// 구갑합 [a, b]
int queryRange(int a, int b)
{
	return query(b) - query(a - 1);
}



int main()
{
	for(int i = 1; i <= N; i++)
		updatePoint(i, arr[i]);

	for(int i = 1; i <= N; i++)
		printf("%2d|", i);
	printf("\n-------------------------------------\n");
	for(int i = 1; i <= N; i++)
		printf("%2d|", fw[i]);
	printf("\n");

	printf("구간합 (1, %d) = %d\n", 5, query(5));
	printf("구간합 (%d, %d) = %d\n", 2, 6, queryRange(2, 6));
	return 0;
}


