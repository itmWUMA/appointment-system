#include "Admin.h"

Admin::Admin()
{
	this->name = "";
	this->pwd = "";
}

Admin::Admin(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;
}

bool Admin::operator==(const Admin& a)
{
	return (this->name == a.name && this->pwd == a.pwd);
}

bool Admin::operator<(const Admin& a) const
{
	return this->name < a.name;
}

void Admin::OpenMenu()
{
	system("cls");

	cout << "��ã�" << this->name << endl;
	cout << "============== ����Ա����ϵͳ ==============" << endl;
	cout << "              [1] ����˺�" << endl;
	cout << "              [2] �鿴�˺�" << endl;
	cout << "              [3] �鿴����" << endl;
	cout << "              [4] ���ԤԼ" << endl;
	cout << "              [0] ע����¼" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Admin::AddPerson()
{
	ofstream ofs;
	string fileName, idName;

	cout << "����������˺ŵ�����([1]ѧ�� | [2]��ʦ) > ";
	int ipt = 0;
	cin >> ipt;


	// ѡ�������
	if (ipt == 1)
	{
		fileName = STU_FILE;
		idName = "ѧ��";
	}
	else if (ipt == 2)
	{
		fileName = TEACHER_FILE;
		idName = "ְ����";
	}
	else
	{
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ¼����Ϣ
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name, pwd;
	cout << "������" << idName << "> ";
	cin >> id;
	cout << "������������> ";
	cin >> name;
	cout << "���������룺> ";
	cin >> pwd;
	ofs << id << ' ' << name << ' ' << pwd << endl;
	ofs.close();
	cout << "¼��ɹ���" << endl;

	system("pause");
	system("cls");
}

void Admin::ShowPerson()
{
}

void Admin::ShowRoomInfo()
{
}

void Admin::ClearFile()
{
}
