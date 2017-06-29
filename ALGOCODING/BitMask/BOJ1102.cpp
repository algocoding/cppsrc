/*
 * 발전소
 * https://www.acmicpc.net/problem/1102
 *
 *  Created on: 2017. 6. 28.
 *      Author: JongYun
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N; 			// 발전소 수
int P; 			// 고장 아닌 발전소 수
int G[16][16];	// i->j 비용


int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
		cin >> G[i][j];

	char t;
	int on = 0, cnt = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> t;
		if(t == 'Y'){
			on |= (1 << i);
			cnt++;
		}
	}
	vector<int> cost;
	for(int i = 0; i < N; i++)
	{
		if((on & (1 << i)) == 0)
		{
			int min = 0xffffffff;
			for(int j = 0; j < N; j++)
			{
				if(i == j) continue;
				if((on & (1 << j)) && G[j][i] && min > G[j][i])
					min = G[j][i];
			}
			cost.push_back(min);
		}
	}
	sort(cost.begin(), cost.end());

	int sum = 0;
	for(int i = 0; i < P - cnt; i++)
		sum += cost[i];

	cout << sum;
	return 0;
}



