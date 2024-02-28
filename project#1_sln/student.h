#ifndef CSTUDENT_H
#define CSTUDENT_H

#include<iostream>
#include<string>
using namespace std;

class CStudent {
	int number;
	string name;
	string major;
public:
	CStudent();
	void set_info(int number, string name, string major);
	int get_number();
	string get_name();
	string get_major();
	CStudent *next;
};

#endif