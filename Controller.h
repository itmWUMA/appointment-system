#pragma once
#include "Identity.h"
#include "Student.h"
#include "Admin.h"
#include "Teacher.h"
#include <fstream>
#include <set>
using namespace std;

/*	���̿�����
	���ڿ��Ƴ���������Լ��û�����
*/
class Controller
{
private:
	set<Student> stus;	// ѧ����Ϣ
	set<Teacher> teachers;	// ��ʦ��Ϣ
	set<Admin> admins;	// ����Ա��Ϣ

	// ѧ������
	void ParseStudent();

	// ��ʦ����
	void ParseTeacher();

	// ����Ա����
	void ParseAdmin();

	// ѧ������
	void StartStudent(Student& stu);

	// ��ʦ����
	void StartTeacher(Teacher& teacher);

	// ����Ա����
	void StartAdmin(Admin& admin);

public:
	Controller();

	// ��ʾ����
	void PrintMenu();

	// ����+��ͣ
	void CleanAndPause();

	/// <summary>
	/// ��¼
	/// </summary>
	/// <param name="type">��¼���</param>
	void Login(Identity::IdentityType type);
};

