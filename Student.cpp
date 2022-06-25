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

void Student::OpenMenu()
{
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
