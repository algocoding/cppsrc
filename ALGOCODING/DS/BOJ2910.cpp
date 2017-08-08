/*
 * BOJ2910>> ºóµµ Á¤·Ä
 * https://www.acmicpc.net/problem/2910
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> cnt;
map<int, int> pos;
typedef struct _arr{
	int val, cnt;
}DATA;
DATA data[1000];

bool compare(DATA & a, DATA & b){
	if(a.cnt == b.cnt)
		return pos[a.val] < pos[b.val];
	else
		return a.cnt > b.cnt;
}
int main()
{
	int N, C;
	scanf("%d%d", &N, &C);
	int val;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &val);

		cnt[val]++;
		if(cnt[val] == 1)
			pos[val] = i;
	}
	int idx = 0;
	map<int,int>::iterator it;
	for(it = cnt.begin(); it != cnt.end(); ++it)
	{
		data[idx].val = it->first;
		data[idx].cnt = it->second;
		idx++;
	}
	sort(data, data + idx, compare);
	for(int i = 0; i < idx; i++)
	{
		for(int j = 0; j < data[i].cnt; j++)
			printf("%d ", data[i].val);
	}
	printf("\n");
	return 0;
}


