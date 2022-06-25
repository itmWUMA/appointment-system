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

	cout << "��ã�" << this->name << "��ʦ" << endl;
	cout << "============== ��ʦ����ϵͳ ==============" << endl;
	cout << "              [1] �鿴����ԤԼ" << endl;
	cout << "              [2] ���ԤԼ" << endl;
	cout << "              [0] ע����¼" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Teacher::ShowAllOrder()
{
}

void Teacher::ValidOrder()
{
}
