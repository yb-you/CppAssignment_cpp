#include <iostream>

#include "student.h"
#include "function.h"

using namespace std;

int main() {
	cout << "학생관리 프로그램을 시작합니다." << endl;
	while (true)
	{
		manu();
		int manu_num;
		cin >> manu_num;
		switch (manu_num)
		{
		case 1:
			insert_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			search_student();
			break;
		case 4:
			sort_num();
			break;
		case 5:
			sort_score();
			break;
		case 6:
			save_file();
			break;
		case 7:
			open_file();
			break;
		case 8:
			exit_();
			return 0;     //프로그램 종료시 while문 탈출
			break;
		default:
			error_();
			break;
		}
	}
}