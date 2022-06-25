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

	cout << "��ã�" << this->name << endl;
	cout << "============== ����Ա����ϵͳ ==============" << endl;
	cout << "              [1] ����˺�" << endl;
	cout << "              [2] �鿴�˺�" << endl;
	cout << "              [3] �鿴����" << endl;
	cout << "              [4] ���ԤԼ" << endl;
	cout << "              [0] ע����¼" << endl;
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
