#include "Student.h"

Student::Student()
{
	this->name = "";
	this->pwd = "";
	this->id = 0;
}

Student::Student(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;
}

bool Student::operator==(const Student& stu)
{
	return (this->name == stu.name && this->pwd == stu.pwd && this->id == stu.id);
}

bool Student::operator<(const Student& stu) const
{
	return this->id < stu.id;
}

void Student::OpenMenu()
{
	system("cls");

	cout << "你好，" << this->name << "同学" << endl;
	cout << "============== 管理员操作系统 ==============" << endl;
	cout << "              [1] 申请预约" << endl;
	cout << "              [2] 查看我的预约" << endl;
	cout << "              [3] 查看所有预约" << endl;
	cout << "              [4] 取消预约" << endl;
	cout << "              [0] 注销登录" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Student::ApplyOrder()
{
}

void Student::ShowMyOrder()
{
}

void Student::ShowAllOrder()
{
}

void Student::CancelOrder()
{
}
