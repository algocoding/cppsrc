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
	mans.insert("������");	mans.insert("��ȣ��");
	mans.insert("���缮");	mans.insert("�豸��");

	set<string>::iterator it;
	for(it = mans.begin(); it != mans.end(); it++)
		cout << it->data() << endl;


	set<string>::reverse_iterator rit;
	for(rit = mans.rbegin(); rit != mans.rend(); rit++)
		cout << rit->c_str() << endl;


	it = mans.find("�豸��");	cout << it->c_str() << endl;

	mans.erase("�豸��");
	if(mans.find("�豸��") == mans.end())
		cout << "�豸�� ����\n";
}



