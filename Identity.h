#pragma once
#include "Global.h"
#include <string>
#include <iostream>
using namespace std;

/* ��ݽӿ�
	��������ݳ���Ϊ��ݽӿڣ��ṩ�û��������롢�����˵�����
*/
class Identity
{
public:
	// �û���
	string name;
	// ����
	string pwd;
	// �������
	enum class IdentityType
	{
		STU,
		TEACHER,
		ADMIN,
	};

	// �����˵�
	virtual void OpenMenu() = 0;

	// �鿴����ԤԼ
	virtual void ShowAllOrder();
};