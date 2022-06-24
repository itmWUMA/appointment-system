#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 显示界面
void PrintMenu()
{
	cout << "============== 机房预约系统 ==============" << endl;
	cout << "              [1] 学生代表" << endl;
	cout << "              [2] 教   师" << endl;
	cout << "              [3] 管 理 员" << endl;
	cout << "              [0] 退   出" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

int main()
{
	int ipt = 0;

	do
	{
		// 显示界面
		PrintMenu();

		// 获取输入
		cin >> ipt;

		// 判断输入
		switch (ipt)
		{
		case 0:	// 退出
			system("cls");
			cout << "Goodbye!" << endl;
			break;
		case 1:	// 学生代表
			break;
		case 2:	// 教师
			break;
		case 3:	// 管理员
			break;
		default:
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (ipt);

	system("pause");

	return 0;
}