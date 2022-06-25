#pragma once
#include "Identity.h"
#include "Student.h"
#include "Admin.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

/*	���̿�����
	���ڿ��Ƴ���������Լ��û�����
*/
class Controller
{
private:
	unordered_set<Student> stus;	// ѧ����Ϣ
	unordered_set<Teacher> teachers;	// ��ʦ��Ϣ
	unordered_set<Admin> admins;	// ����Ա��Ϣ

	// ѧ������
	void ParseStudent();

	// ��ʦ����
	void ParseTeacher();

	// ����Ա����
	void ParseAdmin();

public:
	Controller();

	// ��ʾ����
	void PrintMenu();

	// ����+��ͣ
	void CleanAndPause();

	/// <summary>
	/// ��¼
	/// </summary>
	/// <param name="fileName">�ļ���</param>
	/// <param name="type">��¼���</param>
	void Login(string fileName, Identity::IdentityType type);
};

