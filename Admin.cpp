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
	ofstream ofs;
	string fileName, idName;

	cout << "请输入添加账号的类型([1]学生 | [2]老师) > ";
	int ipt = 0;
	cin >> ipt;


	// 选项的配置
	if (ipt == 1)
	{
		fileName = STU_FILE;
		idName = "学号";
	}
	else if (ipt == 2)
	{
		fileName = TEACHER_FILE;
		idName = "职工号";
	}
	else
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 录入信息
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name, pwd;
	cout << "请输入" << idName << "> ";
	cin >> id;
	cout << "请输入姓名：> ";
	cin >> name;
	cout << "请输入密码：> ";
	cin >> pwd;
	ofs << id << ' ' << name << ' ' << pwd << endl;
	ofs.close();
	cout << "录入成功！" << endl;

	system("pause");
	system("cls");
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
