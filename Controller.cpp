#include "Controller.h"

void Controller::ParseStudent()
{
	// ��ȡ�ļ�
	ifstream ifs(STU_FILE, ios::in | ios::binary);
	// �ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ���������������������stus��
	this->stus.clear();
	Student stu;
	while (ifs.read((char*)(&stu), sizeof(Student)))
		this->stus.insert(stu);

	// �ر��ļ�
	ifs.close();
}

void Controller::ParseTeacher()
{
	// ��ȡ�ļ�
	ifstream ifs(TEACHER_FILE, ios::in | ios::binary);
	// �ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ���������������������teachers��
	this->teachers.clear();
	Teacher t;
	while (ifs.read((char*)(&t), sizeof(Teacher)))
		this->teachers.insert(t);

	// �ر��ļ�
	ifs.close();
}

void Controller::ParseAdmin()
{
	// ��ȡ�ļ�
	ifstream ifs(ADMIN_FILE, ios::in | ios::binary);
	// �ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ���������������������stus��
	this->admins.clear();
	Admin admin;
	while (ifs.read((char*)(&admin), sizeof(Admin)))
		this->admins.insert(admin);

	// �ر��ļ�
	ifs.close();
}

Controller::Controller()
{
	// ������������
	ParseAdmin();
	ParseStudent();
	ParseTeacher();
}

void Controller::PrintMenu()
{
	cout << "============== ����ԤԼϵͳ ==============" << endl;
	cout << "              [1] ѧ������" << endl;
	cout << "              [2] ��   ʦ" << endl;
	cout << "              [3] �� �� Ա" << endl;
	cout << "              [0] ��   ��" << endl;
	cout << "==========================================" << endl;
	cout << "> ";
}

void Controller::CleanAndPause()
{
	system("pause");
	system("cls");
}

void Controller::Login(string fileName, Identity::IdentityType type)
{
	// ��ȡ�ļ�
	ifstream ifs(fileName, ios::in | ios::binary);

	// �ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ��ȡ�û�����
	int id = 0;
	string name, pwd;
	switch (type)
	{
	case Identity::IdentityType::STU:	// ѧ�����
		cout << "������ѧ�ţ�> ";
		cin >> id;
		cout << "���������룺> ";
		cin >> pwd;
		// ����ѧ�����
		

		break;
	case Identity::IdentityType::TEACHER:	// ��ʦ���
		cout << "������ְ���ţ�> ";
		cin >> id;
		cout << "���������룺> ";
		cin >> pwd;
		// ��ʦ�����֤

		break;
	case Identity::IdentityType::ADMIN:	// ����Ա���
		cout << "���������Ա������> ";
		cin >> name;
		cout << "���������룺> ";
		cin >> pwd;
		// ����Ա�����֤

		break;
	default:
		break;
	}

	// ��֤ʧ��
	cout << "��֤��¼ʧ�ܣ�" << endl;
	CleanAndPause();
}
