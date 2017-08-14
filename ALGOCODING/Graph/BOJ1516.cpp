/*
 * BOJ1516.cpp
 * 게임 개발 => https://www.acmicpc.net/problem/1516
 *  Created on: 2017. 8. 14.
 *      Author: JongYun
 */


#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 500;
vector< vector<int> > G(MAXN + 1);			// 벡터 크기
int btime[MAXN + 1], ftime[MAXN + 1];
int indeg[MAXN + 1];

int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &btime[i]);
		while(1)
		{
			int v;
			scanf("%d", &v);
			if(v == -1) break;
			G[i].push_back(v);
			indeg[v]++;		// 진입 차수
		}
	}

	vector<int> Q;
	for(int i = 1; i <= N; i++)
		if(indeg[i] == 0)
		{
			Q.push_back(i);
			ftime[i] = btime[i];
		}

	while(!Q.empty())
	{
		int v = Q.front();
		for(int i = 0; i < G[v].size(); i++)
		{
			if(indeg[G[v][i]])
				indeg[G[v][i]]--;

			if(indeg[G[v][i]] == 0)
			{
				Q.push_back(G[v][i]);
				ftime[i] = ftime[v] + btime[i];
			}
		}
	}

	for(int i = 1; i <= N; i++)
		printf("%d\n", ftime[i]);
	return 0;
}



