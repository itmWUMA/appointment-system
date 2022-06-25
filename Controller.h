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

/*	流程控制类
	用于控制程序的流程以及用户交互
*/
class Controller
{
private:
	set<Student> stus;	// 学生信息
	set<Teacher> teachers;	// 教师信息
	set<Admin> admins;	// 管理员信息
	vector<Room> rooms;	// 机房信息
	multimap<int, Order> orders; // 预约信息

	// 学生解析
	void ParseStudent();

	// 教师解析
	void ParseTeacher();

	// 管理员解析
	void ParseAdmin();

	// 机房解析
	void ParseRoom();

	// 预约解析
	void ParseOrder();

	// 学生操作
	void StartStudent(Student& stu);

	// 教师操作
	void StartTeacher(Teacher& teacher);

	// 管理员操作
	void StartAdmin(Admin& admin);

	// 登出(注销)
	void Logout();

public:
	Controller();

	// 显示界面
	void PrintMenu();

	// 清屏+暂停
	void CleanAndPause();

	// 登录
	void Login(Identity::IdentityType type);
};

