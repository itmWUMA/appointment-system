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

void Teacher::OpenMenu()
{
}

void Teacher::ShowAllOrder()
{
}

void Teacher::ValidOrder()
{
}
