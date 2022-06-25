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

	cout << "��ã�" << this->name << "ͬѧ" << endl;
	cout << "============== ����Ա����ϵͳ ==============" << endl;
	cout << "              [1] ����ԤԼ" << endl;
	cout << "              [2] �鿴�ҵ�ԤԼ" << endl;
	cout << "              [3] �鿴����ԤԼ" << endl;
	cout << "              [4] ȡ��ԤԼ" << endl;
	cout << "              [0] ע����¼" << endl;
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
