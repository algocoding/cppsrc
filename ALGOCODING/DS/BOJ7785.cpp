/*
 * set<string> 클래스 사용
 * https://www.acmicpc.net/problem/7785
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */

#include <cstdio>
#include <set>
#include <string>
using namespace std;

set<string> company;

int main()
{
	int N;
	char name[20], str[10];

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf(" %s %s", name, str);
		if(str[0] == 'e'){
			company.insert(name);
		}else{
			company.erase(name);
		}
	}
	set<string>::reverse_iterator rit;
	for(rit = company.rbegin(); rit != company.rend(); rit++)
	{
		printf("%s\n", rit->c_str());
	}
}
