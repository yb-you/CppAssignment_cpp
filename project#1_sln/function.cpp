#include "student.h"
#include "function.h"

CStudent *listhead = NULL;
void show() {                                  //�л��������
	int i = 1;
	CStudent *search;
	search = listhead;
	while (search != NULL) {
		cout << i << '.' << "�й�:" << search->get_number() << "  ����:" << search->get_name() << "  ����:" << search->get_major() << endl;
		search = search->next;
		i++;
	}
	cout << endl;
}

void manu() {                                  //�޴����
	cout << "�޴�" << endl;
	cout << "1)�߰�" << endl;
	cout << "2)����" << endl;
	cout << "3)�˻�" << endl;
	cout << "4)����" << endl;
	cout << "5)����" << endl;
}

void set_student() {                           //�л��Է�
	CStudent student;
	cout << "�й�>>";
	int number, n = 0;
	cin >> number;

	CStudent *temp = listhead;

	while (temp != NULL) {                                     //�й��ߺ�üũ
		if (temp->get_number() == number) {
			n = 1;
			break;
		}
		else
			n = 0;
		temp = temp->next;
	}

	if (n == 0) {                            //�й��ߺ��� ���� ��
		cout << "����>>";
		string name;
		cin >> name;

		cout << "����>>";
		string major;
		cin >> major;

		student.set_info(number, name, major);         //�л������Է�
		insert_student(student);                       //�Էµ� �л��� ����Ʈ������
		show();
	}
	else if (n == 1) {                      //�й��ߺ��� ���� ��
		cout << "���� �й��� �̹� �ֽ��ϴ�." << endl;
		show();
	}

}
void insert_student(CStudent student) {         //���Ḯ��Ʈ�� �л� ����
	CStudent *temp = new CStudent;
	temp->set_info(student.get_number(), student.get_name(), student.get_major());
	temp->next = listhead;
	listhead = temp;
}

void delete_student() {                   //�л�����
	CStudent *temp, *previous;
	int del_num;

	previous = NULL;
	temp = listhead;
	cout << "�����ϰ��� �ϴ� �й��� �Է��ϼ���." << endl;
	show();
	cin >> del_num;

	while (temp != NULL) {                  //������ �й� ��ġȮ��
		if (temp->get_number() == del_num)
			break;
		previous = temp;
		temp = temp->next;
	}
	if (temp == NULL)                      //������ �й��� ���� ���
		cout << "�ش� �й��� �����ϴ�." << endl;
	else {                                 //������ �й��� �ִ� ���
		if (previous == NULL) {         //�Ǿ��ΰ��
			listhead = temp->next;
			delete temp;
		}
		else {                        //�߰��̳� ��
			previous->next = temp->next;
			delete temp;
		}
	}

	show();


}

void search_student() {                      //�л��˻�
	string name;
	CStudent *temp;
	temp = listhead;
	int i = 0;

	cout << "�˻��ϰ��� �ϴ� ������ �Է��ϼ���>>";
	cin >> name;
	while (temp != NULL) {
		if (temp->get_name() == name) {              //�˻��ϰ��� �ϴ� ������ ���� ��
			cout << "�й�:" << temp->get_number() << "  ����:" << temp->get_name() << "  ����:" << temp->get_major() << endl;
			i++;
		}
		temp = temp->next;
	}
	if (i == 0)                                      //�˻��ϰ��� �ϴ� ������ ���� ��
		cout << "�ش� �ϴ� ������ �����ϴ�." << endl<<endl;

}
void line_student() {                     //�л����� 
	CStudent *a, *b, *c, *i;
	int num = 1;
	a = NULL;
	b = listhead;
	c = b->next;
	i = listhead;
	while (i != NULL) {                    //�л� �� Ȯ��
		num++;
		i = i->next;
	}
	for (int q = 0; q < num; q++) {        //�л�����ŭ �ݺ�
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
					if (b->get_number() > c->get_number()) {     //��ġ����
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
	cout << "���α׷��� �����մϴ�" << endl;
}