#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "student.h"
#include "function.h"

vector<CStudentGrade> v;   //CStudentGrade클래스형 벡터v 선언

void manu() {
		cout << "----------메뉴의 번호를 입력해 주세요.----------" << endl;   //메뉴 출력
		cout << "1)추가 " << endl;
		cout << "2)삭제 " << endl;
		cout << "3)검색 " << endl;
		cout << "4)학번 정렬 " << endl;
		cout << "5)점수 정렬 " << endl;
		cout << "6)파일 저장 " << endl;
		cout << "7)파일 열기 " << endl;
		cout << "8)종료 " << endl;
		cout << "메뉴 선택 >>";
}

void show_student() {                                          //학생리스트 출력 함수
	cout << "-----학생리스트를 출력합니다.-----" << endl;
	cout << "이름>> ";
	for (int i = 0; i < v.size(); i++)                         //이름출력
		if (i == v.size() - 1)                                 //마지막 원소일 경우
			cout << v[i].get_name();                             //탭 문자(\t)제거
		else                                                   //마지막 원소가 아닐 경우
			cout << v[i].get_name() << '\t';                     //구분을 위한 탭 문자(\t)삽입
	cout << endl<<"학번>> ";
	for (int i = 0; i < v.size(); i++)                         //학번 출력
		if (i == v.size() - 1)                                
			cout << v[i].get_num();
		else
			cout << v[i].get_num() << '\t';
	cout << endl<<"점수>> ";
	for (int i = 0; i < v.size(); i++)                          //점수출력
		if (i == v.size() - 1)                                  //마지막 원소일 경우
			cout << v[i].get_score();                             //탭 문자(\t)제거
		else                                                    //마지막 원소가 아닐 경우
			cout << v[i].get_score() << '\t' << '\t';              //구분을 위한 탭 문자 2개 삽입
	cout << endl;
	cout << endl;
}
void insert_student() {                                          //학생추가 함수
	cout << "-----학생을 추가합니다.-----" << endl << "학번, 성명, 점수를 입력해 주세요.>>";
	int num, score;
	string name;
	cin >> num >> name >> score;
	try {                                                         //예외처리 try함수
		if (v.size() != 0) {
			for (int i = 0; i < v.size(); i++)
				if (num == v[i].get_num())                        //중복되는 학번이 있다면
					throw "error: 학번이 중복됩니다.";              //예외처리
		}
		CStudentGrade temp(num, name, score);
		v.push_back(temp);                                    //벡터에 추가
	}
	catch (char* Serror) {                                        //예외처리 carch함수
		cout << Serror << endl;
	}
	show_student();
}
void delete_student() {                                            //학생삭제함수
	cout << "-----학생을 삭제합니다.-----" << endl << "삭제하려는 학생의 학번을 입력해 주세요.>>";
	int delete_num;
	cin >> delete_num;
	vector<CStudentGrade>::iterator it;
	try {                                                          //예외처리 try함수
		for (it = v.begin(); it != v.end();) {
			if (delete_num == it->get_num()) {                     //삭제하려는 학번을 찾은 경우
				throw "삭제하였습니다.";                              //예외처리
			}
			it++;                                                 //다음 원소로 이동
		}
		cout << "error: 삭제하고자 하는 학생이 없습니다." << endl;  //예외처리 되지 않은 경우(삭제하지 못한경우) 오류 출력
	}
	catch (char* Serror) {                                         //예외처리 catch함수
		it = v.erase(it);                                           //해당벡터의 원소 삭제
		cout << Serror << endl;
	}
	show_student();
}
void search_student() {                                             //학생검색함수
	cout << "-----학생을 검색합니다.-----" << endl;
	cout << "검색하려는 학생의 성명을 입력해 주세요.>> ";
	string search_name;
	cin >> search_name;
	int n = 0;
	for (int i = 0; i < v.size(); i++) {
		if (search_name == v[i].get_name()) {                       //검색하려는 성명을 찾은 경우
			v[i].show();                                              //학생정보 출력
			n++;
		}
	}
	try {                                                           //예외처리 try함수
		if (n == 0)                                                 //검색된 학생의 수가 0명인 경우
			throw "error: 검색하고자 하는 학생이 없습니다.";          //예외처리
		else {                                                      //검색된 학생의 수가 0명이 아닌경우(찾은 경우)
			cout << n << "명의 학생이 검색되었습니다." << endl;       //학생 수 출력
		}
	}
	catch (char* Serror) {                                          //예외처리 catch함수
		cout << Serror << endl;
	}
	cout << endl;
}
void sort_num() {                                                    //학번정렬함수
	cout << "-----학번순으로 학생을 정렬합니다.-----" << endl;
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
void sort_score() {                                                 //점수정렬함수
	cout << "-----점수순으로 학생을 정렬합니다.-----" << endl;
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
	double average = ((double)sum / (double)v.size());                 //평균계산

	int ssum = 0;
	double vari;
	double Sdev;
	for (int i = 0; i < v.size(); i++)
		ssum += (v[i].get_score() - average)*(v[i].get_score() - average);
	vari = ssum / v.size();
	Sdev = sqrt(vari);                                                 //표준편차계산
	show_student();
	cout << "평균: " << average << endl;
	cout << "표준편차: " << Sdev << endl;
}
void save_file() {                                                     //파일저장함수
	cout << "-----현재 리스트를 텍스트 파일로 저장합니다.-----" << endl;
	cout << "파일명을 입력해 주세요.>>";
	string file_name;
	cin >> file_name;
	string fsave_name = file_name + ".txt";
	ofstream fout(fsave_name);                                         //입력된 "파일명+.txt"을 쓰기모드로 열기
	try {                                                              //예외처리 try함수
		if (!fout)                                                     //파일을 열지 못한 경우
			throw"error: 파일을 저장하는 데 실패했습니다.";              //예외처리
		else {
			fout << "이름>> ";
			for (int i = 0; i < v.size(); i++)                         //이름출력
				if (i == v.size() - 1)                                 //마지막 원소인 경우
					fout << v[i].get_name();                             //탭 문자 (\t)제거
				else                                                   //마지막 원소가 아닌 경우
					fout << v[i].get_name() << '\t';                     //구분을 위한 탭문자 (\t)삽입
			fout << endl << "학번>> ";
			for (int i = 0; i < v.size(); i++)                         //학번출력
				if (i == v.size() - 1)
					fout << v[i].get_num();
				else
					fout << v[i].get_num() << '\t';
			fout << endl << "점수>> ";
			for (int i = 0; i < v.size(); i++)                           //점수출력
				if (i == v.size() - 1)                                   //마지막 원소인 경우
					fout << v[i].get_score();                              //탭 문자 (\t)제거
				else                                                     //마지막 원소가 아닌 경우
					fout << v[i].get_score() << '\t' << '\t';              //구분을 위한 탭문자 2개 삽입
			cout << "파일 저장이 완료되었습니다." << endl;
			cout << "파일 명: " << fsave_name << endl << endl;
			fout.close();
		}
	}
	catch (char *Serror) {                                                //예외처리 carch함수
		cout << Serror << endl;
	}

}
void open_file() {                                                         //파일열기함수
	cout << "-----저장된 리스트를 불러옵니다.-----" << endl;
	cout << "파일명을 입력해 주세요. >> ";
	string file_name;
	cin >> file_name;
	string fopen_name = file_name + ".txt";
	ifstream fin(fopen_name);                                               //입력된 파일명+.txt을 읽기모드로 열기
	try {                                                                   //예외처리 tr함수
		if (!fin)                                                           //파일을 열지 못한 경우
			throw "error: 파일을 불러오는 데 실패했습니다.";                   //예외처리
		else {
			cout << "파일을 불러오는 데 성공했습니다." << endl;
			cout << "파일 명: " << fopen_name << endl;
			char buf[256];
			while (!fin.eof()) {          
				fin.getline(buf, 256);    //문자 읽기
				cout << buf << endl;      //문자 출력
			}
			cout << endl;
			fin.close();
		}
	}
	catch (char* Serror) {                                                   //예외처리 carch함수
		cout << Serror << endl;
	}
}
void exit_() {
	cout << "프로그램을 종료합니다." << endl;
}
void error_() {
	cout << "error: 잘못된 메뉴입니다." << endl;
}