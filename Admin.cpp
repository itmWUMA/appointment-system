#include "Admin.h"

Admin::Admin()
{
	this->name = "";
	this->pwd = "";
}

Admin::Admin(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;
}

bool Admin::operator==(const Admin& a)
{
	return (this->name == a.name && this->pwd == a.pwd);
}

bool Admin::operator<(const Admin& a) const
{
	return this->name < a.name;
}

void Admin::OpenMenu()
{
	system("cls");

	cout << "你好，" << this->name << endl;
	cout << "============== 管理员操作系统 ==============" << endl;
	cout << "              [1] 添加账号" << endl;
	cout << "              [2] 查看账号" << endl;
	cout << "              [3] 查看机房" << endl;
	cout << "              [4] 清空预约" << endl;
	cout << "              [0] 注销登录" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Admin::AddPerson()
{

}

void Admin::ShowPerson()
{
}

void Admin::ShowRoomInfo()
{
}

void Admin::ClearFile()
{
}
