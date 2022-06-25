#pragma once
#include "Identity.h"
#include "Student.h"
#include "Admin.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

/*	流程控制类
	用于控制程序的流程以及用户交互
*/
class Controller
{
private:
	unordered_set<Student> stus;	// 学生信息
	unordered_set<Teacher> teachers;	// 教师信息
	unordered_set<Admin> admins;	// 管理员信息

	// 学生解析
	void ParseStudent();

	// 教师解析
	void ParseTeacher();

	// 管理员解析
	void ParseAdmin();

public:
	Controller();

	// 显示界面
	void PrintMenu();

	// 清屏+暂停
	void CleanAndPause();

	/// <summary>
	/// 登录
	/// </summary>
	/// <param name="fileName">文件名</param>
	/// <param name="type">登录身份</param>
	void Login(string fileName, Identity::IdentityType type);
};

