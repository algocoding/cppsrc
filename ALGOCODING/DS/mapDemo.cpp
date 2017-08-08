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
	m.insert(pair<string ,int>("강호동", 1));
	m["이휘재"] = 2;
	m["유재석"] = 3;
	m["김구라"] = 4;

	map<string, int>::iterator it;

	for(it = m.begin(); it != m.end(); it++)
		cout << it->first << ',' << it->second << endl;

	cout << m["유재석"] << endl;

}


