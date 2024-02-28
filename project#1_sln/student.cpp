#include "student.h"

CStudent::CStudent() {}
void CStudent::set_info(int number, string name, string major) {
	this->number = number;
	this->name = name;
	this->major = major;
}
int CStudent::get_number() { return number; }
string CStudent::get_name() { return name; }
string CStudent::get_major() { return major; }
