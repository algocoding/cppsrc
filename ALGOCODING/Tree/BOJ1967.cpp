/*
 * 트리의 지름(https://www.acmicpc.net/problem/1967)
 *
 *  Created on: 2017. 7. 23.
 *      Author: JongYun
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 10000;	// 노드 번호는 1..10000, 루트는 항상 1
int V;
vector<pair<int, int> > G[10001];
int radius = 0;

int postorder(int v)
{
	int n = G[v].size();
	if( n == 0) return 0;

	vector<int> ret;
	for(int i = 0; i < n; i++)
	{
		int w = postorder(G[v][i].first) + G[v][i].second;
		ret.push_back(w);
	}
	sort(ret.begin(), ret.end(), greater<int>());

	if(ret.size() == 1)
		radius = max(radius, ret[0]);
	else
		radius = max(radius, ret[0] + ret[1]);
	return ret[0];
}
int main()
{
	cin >> V;
	for(int i = 0; i < V - 1; i++)
	{
		int p, v, w;
		cin >> p >> v >> w;

		G[p].push_back(pair<int, int>(v, w));
	}
	postorder(1);
	cout << radius;
}

