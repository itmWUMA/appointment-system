#include "Controller.h"

void Controller::PrintMenu()
{
	cout << "============== 机房预约系统 ==============" << endl;
	cout << "              [1] 学生代表" << endl;
	cout << "              [2] 教   师" << endl;
	cout << "              [3] 管 理 员" << endl;
	cout << "              [0] 退   出" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Controller::CleanAndPause()
{
	system("pause");
	system("cls");
}
