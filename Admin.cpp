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

void Admin::OpenMenu()
{
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
