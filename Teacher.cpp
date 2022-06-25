#include "Teacher.h"

Teacher::Teacher()
{
	this->id = 0;
	this->name = "";
	this->pwd = "";
}

Teacher::Teacher(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;
}

bool Teacher::operator==(const Teacher& t)
{
	return (this->id == t.id && this->name == t.name && this->pwd == t.pwd);
}

bool Teacher::operator<(const Teacher& t) const
{
	return this->id < t.id;
}

void Teacher::OpenMenu()
{
	system("cls");

	cout << "你好，" << this->name << "老师" << endl;
	cout << "============== 教师操作系统 ==============" << endl;
	cout << "              [1] 查看所有预约" << endl;
	cout << "              [2] 审核预约" << endl;
	cout << "              [0] 注销登录" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Teacher::ShowAllOrder()
{
}

void Teacher::ValidOrder()
{
}
