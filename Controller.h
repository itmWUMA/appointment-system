#pragma once
#include "Identity.h"
#include <iostream>
#include <fstream>
using namespace std;

/*	���̿�����
	���ڿ��Ƴ���������Լ��û�����
*/
class Controller
{
public:
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

