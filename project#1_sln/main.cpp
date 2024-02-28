#include "student.h"
#include "function.h"

int main()
{
	int i = 0;
	while (i != 5) {
		manu();
		cin >> i;
		switch (i)
		{
		case 1:
			set_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			search_student();
			break;
		case 4:
			line_student();
			break;
		case 5:
			exit();
			break;
		default:
			cout << "잘못된 메뉴입니다" << endl << endl;
			break;
		}
	}

}