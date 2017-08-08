/*
 * BOJ10828.cpp	https://www.acmicpc.net/problem/10828
 *
 *  Created on: 2017. 7. 24.
 *      Author: JongYun
 */

#include <ext/hash_map>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;

const int MAXN = 10000;
int stack[10000], top = -1;

int main()
{

	//hash_map <const char*, int, hash<const char*>, eqstr> command;
	hash_map <const char*, int> command;
	command["push"] = 0;
	command["pop"] = 1;
	command["size"] = 2;
	command["empty"] = 3;
	command["top"] = 4;

	int N, item;
	cin >> N;
	cout << N << endl;
	for(int i = 0; i < N; i++)
	{
		char str[10];
		cin >> str;

		switch(command[str])
		{
		case 0:
			cin >> item;
			stack[++top] = item;
			break;
		case 1:
			if(top == -1) cout << -1 << endl;
			else cout << stack[top]-- << endl;
			break;
		case 2:
			cout << top + 1 << endl;
			break;
		case 3:
			if(top == -1) cout << 1 << endl;
			else cout << 0 << endl;
			break;
		case 4:
			if(top == -1) cout << -1 << endl;
			else cout << stack[top] << endl;
			break;
		default:
			cout << "default....command" << endl;
		}
	}

	return 0;
}
