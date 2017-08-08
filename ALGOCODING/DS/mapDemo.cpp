/*
 * mapDemo.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> m;
	m.insert(pair<string ,int>("��ȣ��", 1));
	m["������"] = 2;
	m["���缮"] = 3;
	m["�豸��"] = 4;

	map<string, int>::iterator it;

	for(it = m.begin(); it != m.end(); it++)
		cout << it->first << ',' << it->second << endl;

	cout << m["���缮"] << endl;

}


