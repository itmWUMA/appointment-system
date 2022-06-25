#pragma once
#include "Identity.h"
#include <iostream>
#include <fstream>
using namespace std;

/*	流程控制类
	用于控制程序的流程以及用户交互
*/
class Controller
{
public:
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

