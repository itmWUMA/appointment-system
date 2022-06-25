#pragma once
#include "Global.h"
#include <string>
#include <iostream>
using namespace std;

/* 身份接口
	将三种身份抽象为身份接口，提供用户名、密码、操作菜单操作
*/
class Identity
{
public:
	// 用户名
	string name;
	// 密码
	string pwd;
	// 身份类型
	enum class IdentityType
	{
		STU,
		TEACHER,
		ADMIN,
	};

	// 操作菜单
	virtual void OpenMenu() = 0;

	// 查看所有预约
	virtual void ShowAllOrder();
};