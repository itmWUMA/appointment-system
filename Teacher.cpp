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

void Teacher::OpenMenu()
{
}

void Teacher::ShowAllOrder()
{
}

void Teacher::ValidOrder()
{
}
