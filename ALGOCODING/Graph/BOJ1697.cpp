/*
 * BOJ1697.cpp
 * ¼û¹Ú²ÀÁú https://www.acmicpc.net/problem/1697
 *  Created on: 2017. 8. 16.
 *      Author: JongYun
 */


#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 100000;
queue< pair<int,int> > Q;
bool visit[MAX + 1];

int main()
{
	int from, to;
	scanf("%d%d", &from, &to);

	Q.push(pair<int,int>(0, from));
	visit[from] = true;
	pair<int,int> tmp;

	while(!Q.empty())
	{
		tmp = Q.front();
		Q.pop();

		if(tmp.second == to) break;

		if(tmp.second - 1 >= 0 && !visit[tmp.second - 1])
		{
			Q.push(pair<int,int>(tmp.first + 1, tmp.second - 1));
			visit[tmp.second - 1] = true;
		}
		if(tmp.second + 1 <= MAX && !visit[tmp.second + 1])
		{
			Q.push(pair<int,int>(tmp.first + 1, tmp.second + 1));
			visit[tmp.second + 1] = true;
		}

		if(tmp.second * 2 <= MAX && !visit[tmp.second * 2])
		{
			Q.push(pair<int,int>(tmp.first + 1, tmp.second * 2));
			visit[tmp.second * 2] = true;
		}
	}

	printf("%d\n", tmp.first);
	return 0;
}

