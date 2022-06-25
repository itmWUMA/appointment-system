#define _CRT_SECURE_NO_WARNINGS
#include "Controller.h"

int main()
{
	int ipt = 0;
	// 创建管理类对象
	Controller controller;

	do
	{
		// 显示界面
		controller.PrintMenu();

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
			controller.Login(Identity::IdentityType::STU);
			break;
		case 2:	// 教师
			controller.Login(Identity::IdentityType::TEACHER);
			break;
		case 3:	// 管理员
			controller.Login(Identity::IdentityType::ADMIN);
			break;
		default:
			cout << "输入错误！" << endl;
			controller.CleanAndPause();
			break;
		}
	} while (ipt);

	system("pause");

	return 0;
}