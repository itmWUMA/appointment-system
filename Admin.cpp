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

void Admin::ShowPerson(const set<Student>& stus, const set<Teacher>& teachers)
{
	cout << "��������Ҫ���ҵ��˺�����([1]ѧ�� | [2]��ʦ)��> ";
	int ipt = 0;
	cin >> ipt;
	if (ipt == 1)
	{
		for (set<Student>::iterator itor = stus.begin(); itor != stus.end(); itor++)
			cout << itor->id << " " << itor->name << " " << itor->pwd << endl;
	}
	else if (ipt == 2)
	{
		for (set<Teacher>::iterator itor = teachers.begin(); itor != teachers.end(); itor++)
			cout << itor->id << " " << itor->name << " " << itor->pwd << endl;
	}
	else
	{
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");
}

void Admin::ShowRoomInfo(const vector<Room>& rooms)
{
	cout << "������Ϣ���£�(�������  �������  ��ǰ��ռ������)" << endl;
	for (vector<Room>::const_iterator itor = rooms.begin(); itor != rooms.end(); itor++)
		cout << itor->id << " " << itor->capcity << " " << itor->size << endl;

	system("pause");
	system("cls");
}

void Admin::ClearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "ԤԼ����գ�" << endl;
	system("pause");
	system("cls");
}
