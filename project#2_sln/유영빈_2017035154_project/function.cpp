#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "student.h"
#include "function.h"

vector<CStudentGrade> v;   //CStudentGradeŬ������ ����v ����

void manu() {
		cout << "----------�޴��� ��ȣ�� �Է��� �ּ���.----------" << endl;   //�޴� ���
		cout << "1)�߰� " << endl;
		cout << "2)���� " << endl;
		cout << "3)�˻� " << endl;
		cout << "4)�й� ���� " << endl;
		cout << "5)���� ���� " << endl;
		cout << "6)���� ���� " << endl;
		cout << "7)���� ���� " << endl;
		cout << "8)���� " << endl;
		cout << "�޴� ���� >>";
}

void show_student() {                                          //�л�����Ʈ ��� �Լ�
	cout << "-----�л�����Ʈ�� ����մϴ�.-----" << endl;
	cout << "�̸�>> ";
	for (int i = 0; i < v.size(); i++)                         //�̸����
		if (i == v.size() - 1)                                 //������ ������ ���
			cout << v[i].get_name();                             //�� ����(\t)����
		else                                                   //������ ���Ұ� �ƴ� ���
			cout << v[i].get_name() << '\t';                     //������ ���� �� ����(\t)����
	cout << endl<<"�й�>> ";
	for (int i = 0; i < v.size(); i++)                         //�й� ���
		if (i == v.size() - 1)                                
			cout << v[i].get_num();
		else
			cout << v[i].get_num() << '\t';
	cout << endl<<"����>> ";
	for (int i = 0; i < v.size(); i++)                          //�������
		if (i == v.size() - 1)                                  //������ ������ ���
			cout << v[i].get_score();                             //�� ����(\t)����
		else                                                    //������ ���Ұ� �ƴ� ���
			cout << v[i].get_score() << '\t' << '\t';              //������ ���� �� ���� 2�� ����
	cout << endl;
	cout << endl;
}
void insert_student() {                                          //�л��߰� �Լ�
	cout << "-----�л��� �߰��մϴ�.-----" << endl << "�й�, ����, ������ �Է��� �ּ���.>>";
	int num, score;
	string name;
	cin >> num >> name >> score;
	try {                                                         //����ó�� try�Լ�
		if (v.size() != 0) {
			for (int i = 0; i < v.size(); i++)
				if (num == v[i].get_num())                        //�ߺ��Ǵ� �й��� �ִٸ�
					throw "error: �й��� �ߺ��˴ϴ�.";              //����ó��
		}
		CStudentGrade temp(num, name, score);
		v.push_back(temp);                                    //���Ϳ� �߰�
	}
	catch (char* Serror) {                                        //����ó�� carch�Լ�
		cout << Serror << endl;
	}
	show_student();
}
void delete_student() {                                            //�л������Լ�
	cout << "-----�л��� �����մϴ�.-----" << endl << "�����Ϸ��� �л��� �й��� �Է��� �ּ���.>>";
	int delete_num;
	cin >> delete_num;
	vector<CStudentGrade>::iterator it;
	try {                                                          //����ó�� try�Լ�
		for (it = v.begin(); it != v.end();) {
			if (delete_num == it->get_num()) {                     //�����Ϸ��� �й��� ã�� ���
				throw "�����Ͽ����ϴ�.";                              //����ó��
			}
			it++;                                                 //���� ���ҷ� �̵�
		}
		cout << "error: �����ϰ��� �ϴ� �л��� �����ϴ�." << endl;  //����ó�� ���� ���� ���(�������� ���Ѱ��) ���� ���
	}
	catch (char* Serror) {                                         //����ó�� catch�Լ�
		it = v.erase(it);                                           //�ش纤���� ���� ����
		cout << Serror << endl;
	}
	show_student();
}
void search_student() {                                             //�л��˻��Լ�
	cout << "-----�л��� �˻��մϴ�.-----" << endl;
	cout << "�˻��Ϸ��� �л��� ������ �Է��� �ּ���.>> ";
	string search_name;
	cin >> search_name;
	int n = 0;
	for (int i = 0; i < v.size(); i++) {
		if (search_name == v[i].get_name()) {                       //�˻��Ϸ��� ������ ã�� ���
			v[i].show();                                              //�л����� ���
			n++;
		}
	}
	try {                                                           //����ó�� try�Լ�
		if (n == 0)                                                 //�˻��� �л��� ���� 0���� ���
			throw "error: �˻��ϰ��� �ϴ� �л��� �����ϴ�.";          //����ó��
		else {                                                      //�˻��� �л��� ���� 0���� �ƴѰ��(ã�� ���)
			cout << n << "���� �л��� �˻��Ǿ����ϴ�." << endl;       //�л� �� ���
		}
	}
	catch (char* Serror) {                                          //����ó�� catch�Լ�
		cout << Serror << endl;
	}
	cout << endl;
}
void sort_num() {                                                    //�й������Լ�
	cout << "-----�й������� �л��� �����մϴ�.-----" << endl;
	for (int j = 0; j < v.size()-1; j++) {
		for (int i = j+1; i < v.size(); i++) {
			if (v[j].get_num() > v[i].get_num()) {
				CStudentGrade temp;
				temp = v.at(j);
				v.at(j) = v.at(i);
				v.at(i) = temp;
			}
		}
	}
	show_student();
}
void sort_score() {                                                 //���������Լ�
	cout << "-----���������� �л��� �����մϴ�.-----" << endl;
	for (int j = 0; j < v.size()-1; j++) {
		for (int i = j+1; i < v.size(); i++) {
			if (v[j].get_score() < v[i].get_score()) {
				CStudentGrade temp;
				temp = v.at(j);
				v.at(j) = v.at(i);
				v.at(i) = temp;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i].get_score();
	double average = ((double)sum / (double)v.size());                 //��հ��

	int ssum = 0;
	double vari;
	double Sdev;
	for (int i = 0; i < v.size(); i++)
		ssum += (v[i].get_score() - average)*(v[i].get_score() - average);
	vari = ssum / v.size();
	Sdev = sqrt(vari);                                                 //ǥ���������
	show_student();
	cout << "���: " << average << endl;
	cout << "ǥ������: " << Sdev << endl;
}
void save_file() {                                                     //���������Լ�
	cout << "-----���� ����Ʈ�� �ؽ�Ʈ ���Ϸ� �����մϴ�.-----" << endl;
	cout << "���ϸ��� �Է��� �ּ���.>>";
	string file_name;
	cin >> file_name;
	string fsave_name = file_name + ".txt";
	ofstream fout(fsave_name);                                         //�Էµ� "���ϸ�+.txt"�� ������� ����
	try {                                                              //����ó�� try�Լ�
		if (!fout)                                                     //������ ���� ���� ���
			throw"error: ������ �����ϴ� �� �����߽��ϴ�.";              //����ó��
		else {
			fout << "�̸�>> ";
			for (int i = 0; i < v.size(); i++)                         //�̸����
				if (i == v.size() - 1)                                 //������ ������ ���
					fout << v[i].get_name();                             //�� ���� (\t)����
				else                                                   //������ ���Ұ� �ƴ� ���
					fout << v[i].get_name() << '\t';                     //������ ���� �ǹ��� (\t)����
			fout << endl << "�й�>> ";
			for (int i = 0; i < v.size(); i++)                         //�й����
				if (i == v.size() - 1)
					fout << v[i].get_num();
				else
					fout << v[i].get_num() << '\t';
			fout << endl << "����>> ";
			for (int i = 0; i < v.size(); i++)                           //�������
				if (i == v.size() - 1)                                   //������ ������ ���
					fout << v[i].get_score();                              //�� ���� (\t)����
				else                                                     //������ ���Ұ� �ƴ� ���
					fout << v[i].get_score() << '\t' << '\t';              //������ ���� �ǹ��� 2�� ����
			cout << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
			cout << "���� ��: " << fsave_name << endl << endl;
			fout.close();
		}
	}
	catch (char *Serror) {                                                //����ó�� carch�Լ�
		cout << Serror << endl;
	}

}
void open_file() {                                                         //���Ͽ����Լ�
	cout << "-----����� ����Ʈ�� �ҷ��ɴϴ�.-----" << endl;
	cout << "���ϸ��� �Է��� �ּ���. >> ";
	string file_name;
	cin >> file_name;
	string fopen_name = file_name + ".txt";
	ifstream fin(fopen_name);                                               //�Էµ� ���ϸ�+.txt�� �б���� ����
	try {                                                                   //����ó�� tr�Լ�
		if (!fin)                                                           //������ ���� ���� ���
			throw "error: ������ �ҷ����� �� �����߽��ϴ�.";                   //����ó��
		else {
			cout << "������ �ҷ����� �� �����߽��ϴ�." << endl;
			cout << "���� ��: " << fopen_name << endl;
			char buf[256];
			while (!fin.eof()) {          
				fin.getline(buf, 256);    //���� �б�
				cout << buf << endl;      //���� ���
			}
			cout << endl;
			fin.close();
		}
	}
	catch (char* Serror) {                                                   //����ó�� carch�Լ�
		cout << Serror << endl;
	}
}
void exit_() {
	cout << "���α׷��� �����մϴ�." << endl;
}
void error_() {
	cout << "error: �߸��� �޴��Դϴ�." << endl;
}