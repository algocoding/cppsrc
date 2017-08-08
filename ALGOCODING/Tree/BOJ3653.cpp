/*
 * BOJ3653.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */


#include <cstdio>
#include <cstring>
using namespace std;

int N, M;
int pos[100001];
int fw[200010];

inline int LSB(int x){	return x & -x; }

void updatePoint(int p, int v)
{
	for( ;p <= N + M; p += LSB(p))
		fw[p] += v;
}
// 구간합 [1, a]
int query(int a)
{
	int sum = 0;
	for( ;a > 0; a -= LSB(a))
		sum += fw[a];
	return sum;
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int tc = 0; tc < T; tc++)
	{
		scanf("%d%d", &N, &M); // dvd 수, dvd 관람수

		for(int i = 1; i <= M + N; i++)	fw[i] = 0;

		for(int i = 1; i <= N; i++)
		{
			pos[i] = M + i;
			updatePoint(M + i,1);
		}

		int dvd, top = M;
		for(int i = 0; i < M; i++)
		{
			scanf("%d", &dvd);
			printf("%d ", query(pos[dvd] - 1) );
			updatePoint(pos[dvd], -1);
			pos[dvd] = top;
			updatePoint(top, 1);
			top--;
		}
		printf("\n");
	}
	return 0;
}

