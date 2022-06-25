#pragma once
#include "Identity.h"
#include "Student.h"
#include "Admin.h"
#include "Teacher.h"
#include "Room.h"
#include <fstream>
#include <set>
#include <vector>
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
	vector<Room> rooms;	// ������Ϣ
	multimap<int, Order> orders; // ԤԼ��Ϣ

	// ѧ������
	void ParseStudent();

	// ��ʦ����
	void ParseTeacher();

	// ����Ա����
	void ParseAdmin();

	// ��������
	void ParseRoom();

	// ԤԼ����
	void ParseOrder();

	// ѧ������
	void StartStudent(Student& stu);

	// ��ʦ����
	void StartTeacher(Teacher& teacher);

	// ����Ա����
	void StartAdmin(Admin& admin);

	// �ǳ�(ע��)
	void Logout();

public:
	Controller();

	// ��ʾ����
	void PrintMenu();

	// ����+��ͣ
	void CleanAndPause();

	// ��¼
	void Login(Identity::IdentityType type);
};

