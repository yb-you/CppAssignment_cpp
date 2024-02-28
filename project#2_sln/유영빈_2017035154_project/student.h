#include <iostream>
#include <string>
#ifndef CSTUDENT_H
#define CSTUDENT_H

using namespace std;
class CStudentGrade {
	int num, score;
	string name;
public:
	CStudentGrade(int num = 0, string name = "", int score = 0);
	void set_info(int num, string name, int score);
	void show();
	int get_num();
	int get_score();
	string get_name();
};
#endif