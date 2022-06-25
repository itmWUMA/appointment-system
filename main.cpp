#define _CRT_SECURE_NO_WARNINGS
#include "Controller.h"

int main()
{
	int ipt = 0;
	// �������������
	Controller controller;

	do
	{
		// ��ʾ����
		controller.PrintMenu();

		// ��ȡ����
		cin >> ipt;

		// �ж�����
		switch (ipt)
		{
		case 0:	// �˳�
			system("cls");
			cout << "Goodbye!" << endl;
			break;
		case 1:	// ѧ������
			controller.Login(STU_FILE, Identity::IdentityType::STU);
			break;
		case 2:	// ��ʦ
			controller.Login(TEACHER_FILE, Identity::IdentityType::TEACHER);
			break;
		case 3:	// ����Ա
			controller.Login(ADMIN_FILE, Identity::IdentityType::ADMIN);
			break;
		default:
			cout << "�������" << endl;
			controller.CleanAndPause();
			break;
		}
	} while (ipt);

	system("pause");

	return 0;
}