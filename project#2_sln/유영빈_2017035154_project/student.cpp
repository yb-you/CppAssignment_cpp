#include<iostream>
#include<string>
using namespace std;

#include "student.h"

CStudentGrade::CStudentGrade(int num, string name, int score) {
	this->num = num; this->name = name; this->score = score;
}
void CStudentGrade::set_info(int num, string name, int score) {
	this->num = num; this->name = name; this->score = score;
}
void CStudentGrade::show() {
	cout << "�й�: " << num << '\t' << "�̸�: " << name << '\t' << "����: " << score << endl;
}
int CStudentGrade::get_num() {
	return num;
}
int CStudentGrade::get_score() {
	return score;
}
string CStudentGrade::get_name() {
	return name;
}