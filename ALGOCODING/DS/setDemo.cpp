/*
 * setDemo.cpp
 *
 *  Created on: 2017. 8. 7.
 *      Author: JongYun
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<string> mans;
	mans.insert("¿Ã»÷¿Á");	mans.insert("∞≠»£µø");
	mans.insert("¿Ø¿ÁºÆ");	mans.insert("±Ë±∏∂Û");

	set<string>::iterator it;
	for(it = mans.begin(); it != mans.end(); it++)
		cout << it->data() << endl;


	set<string>::reverse_iterator rit;
	for(rit = mans.rbegin(); rit != mans.rend(); rit++)
		cout << rit->c_str() << endl;


	it = mans.find("±Ë±∏∂Û");	cout << it->c_str() << endl;

	mans.erase("±Ë±∏∂Û");
	if(mans.find("±Ë±∏∂Û") == mans.end())
		cout << "±Ë±∏∂Û æ¯¿Ω\n";
}



