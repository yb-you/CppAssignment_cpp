#include "student.h"
#include "function.h"

CStudent *listhead = NULL;
void show() {                                  //학생정보출력
	int i = 1;
	CStudent *search;
	search = listhead;
	while (search != NULL) {
		cout << i << '.' << "학번:" << search->get_number() << "  성명:" << search->get_name() << "  전공:" << search->get_major() << endl;
		search = search->next;
		i++;
	}
	cout << endl;
}

void manu() {                                  //메뉴출력
	cout << "메뉴" << endl;
	cout << "1)추가" << endl;
	cout << "2)삭제" << endl;
	cout << "3)검색" << endl;
	cout << "4)정렬" << endl;
	cout << "5)종료" << endl;
}

void set_student() {                           //학생입력
	CStudent student;
	cout << "학번>>";
	int number, n = 0;
	cin >> number;

	CStudent *temp = listhead;

	while (temp != NULL) {                                     //학번중복체크
		if (temp->get_number() == number) {
			n = 1;
			break;
		}
		else
			n = 0;
		temp = temp->next;
	}

	if (n == 0) {                            //학번중복이 없을 때
		cout << "성명>>";
		string name;
		cin >> name;

		cout << "전공>>";
		string major;
		cin >> major;

		student.set_info(number, name, major);         //학생정보입력
		insert_student(student);                       //입력된 학생을 리스트에삽입
		show();
	}
	else if (n == 1) {                      //학번중복이 있을 때
		cout << "같은 학번이 이미 있습니다." << endl;
		show();
	}

}
void insert_student(CStudent student) {         //연결리스트에 학생 삽입
	CStudent *temp = new CStudent;
	temp->set_info(student.get_number(), student.get_name(), student.get_major());
	temp->next = listhead;
	listhead = temp;
}

void delete_student() {                   //학생삭제
	CStudent *temp, *previous;
	int del_num;

	previous = NULL;
	temp = listhead;
	cout << "삭제하고자 하는 학번을 입력하세요." << endl;
	show();
	cin >> del_num;

	while (temp != NULL) {                  //삭제할 학번 위치확인
		if (temp->get_number() == del_num)
			break;
		previous = temp;
		temp = temp->next;
	}
	if (temp == NULL)                      //삭제할 학번이 없는 경우
		cout << "해당 학번이 없습니다." << endl;
	else {                                 //삭제할 학번이 있는 경우
		if (previous == NULL) {         //맨앞인경우
			listhead = temp->next;
			delete temp;
		}
		else {                        //중간이나 끝
			previous->next = temp->next;
			delete temp;
		}
	}

	show();


}

void search_student() {                      //학생검색
	string name;
	CStudent *temp;
	temp = listhead;
	int i = 0;

	cout << "검색하고자 하는 성명을 입력하세요>>";
	cin >> name;
	while (temp != NULL) {
		if (temp->get_name() == name) {              //검색하고자 하는 성명이 있을 때
			cout << "학번:" << temp->get_number() << "  성명:" << temp->get_name() << "  전공:" << temp->get_major() << endl;
			i++;
		}
		temp = temp->next;
	}
	if (i == 0)                                      //검색하고자 하는 성명이 없을 때
		cout << "해당 하는 성명이 없습니다." << endl<<endl;

}
void line_student() {                     //학생정렬 
	CStudent *a, *b, *c, *i;
	int num = 1;
	a = NULL;
	b = listhead;
	c = b->next;
	i = listhead;
	while (i != NULL) {                    //학생 수 확인
		num++;
		i = i->next;
	}
	for (int q = 0; q < num; q++) {        //학생수만큼 반복
		{
			if (b->get_number() > c->get_number()) {
				listhead = c;
				b->next = c->next;
				c->next = b;
			}
			while (b != NULL) {
				a = b;
				b = c;
				c = c->next;
				if (c == NULL)
					break;
				else {
					if (b->get_number() > c->get_number()) {     //위치변경
						a->next = c;
						b->next = c->next;
						c->next = b;
					}
				}
			}
			a = NULL;
			b = listhead;
			c = b->next;
		}
	}

	show();
}
void exit() {
	cout << "프로그램을 종료합니다" << endl;
}