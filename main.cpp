#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ��ʾ����
void PrintMenu()
{
	cout << "============== ����ԤԼϵͳ ==============" << endl;
	cout << "              [1] ѧ������" << endl;
	cout << "              [2] ��   ʦ" << endl;
	cout << "              [3] �� �� Ա" << endl;
	cout << "              [0] ��   ��" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

int main()
{
	int ipt = 0;

	do
	{
		// ��ʾ����
		PrintMenu();

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
			break;
		case 2:	// ��ʦ
			break;
		case 3:	// ����Ա
			break;
		default:
			cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (ipt);

	system("pause");

	return 0;
}