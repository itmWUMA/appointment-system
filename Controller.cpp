#include "Controller.h"

void Controller::ParseStudent()
{
	// ��ȡ�ļ�
	ifstream ifs(STU_FILE, ios::in);
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
	while (ifs >> stu.id && ifs >> stu.name && ifs >> stu.pwd)
		this->stus.insert(stu);

	// �ر��ļ�
	ifs.close();
}

void Controller::ParseTeacher()
{
	// ��ȡ�ļ�
	ifstream ifs(TEACHER_FILE, ios::in);
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
	while (ifs >> t.id && ifs >> t.name && ifs >> t.pwd)
		this->teachers.insert(t);

	// �ر��ļ�
	ifs.close();
}

void Controller::ParseAdmin()
{
	// ��ȡ�ļ�
	ifstream ifs(ADMIN_FILE, ios::in);
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
	while (ifs >> admin.name && ifs >> admin.pwd)
		this->admins.insert(admin);

	// �ر��ļ�
	ifs.close();
}

void Controller::StartStudent(Student& stu)
{
	// ��ʾҳ��
	stu.OpenMenu();
}

void Controller::StartTeacher(Teacher& teacher)
{
	// ��ʾҳ��
	teacher.OpenMenu();
}

void Controller::StartAdmin(Admin& admin)
{
	int ipt = 0;
	do
	{
		// ��ʾҳ��
		admin.OpenMenu();

		// ��ȡ����
		cin >> ipt;
		switch (ipt)
		{
		case 0: // ע��
			cout << "ע���ɹ���" << endl;
			CleanAndPause();
			break;

		case 1: // ����˺�
			admin.AddPerson();
			// ˢ��set
			ParseStudent();
			ParseTeacher();
			break;

		case 2: // �鿴�˺�
			admin.ShowPerson();
			break;

		case 3: // �鿴����
			admin.ShowRoomInfo();
			break;

		case 4: // ���ԤԼ
			admin.ClearFile();
			break;

		default:
			break;
		}
	} while (ipt);
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

void Controller::Login(Identity::IdentityType type)
{
	Student stu;
	Admin admin;
	Teacher teacher;

	// ��ȡ�û�����
	int id = 0;
	string name, pwd;
	switch (type)
	{
	case Identity::IdentityType::STU:	// ѧ�����
		cout << "������ѧ�ţ�> ";
		cin >> id;
		cout << "������������> ";
		cin >> name;
		cout << "���������룺> ";
		cin >> pwd;
		// ѧ����֤���
		stu = Student(id, name, pwd);
		if (stus.find(stu) != stus.end())
		{
			// ����ѧ������
			StartStudent(stu);
			return;
		}
		break;

	case Identity::IdentityType::TEACHER:	// ��ʦ���
		cout << "������ְ���ţ�> ";
		cin >> id;
		cout << "������������> ";
		cin >> name;
		cout << "���������룺> ";
		cin >> pwd;
		// ��ʦ�����֤
		teacher = Teacher(id, name, pwd);
		if (teachers.find(teacher) != teachers.end())
		{
			// �����ʦ����
			StartTeacher(teacher);
			return;
		}
		break;

	case Identity::IdentityType::ADMIN:	// ����Ա���
		cout << "���������Ա������> ";
		cin >> name;
		cout << "���������룺> ";
		cin >> pwd;
		// ����Ա�����֤
		admin = Admin(name, pwd);
		if (admins.find(admin) != admins.end())
		{
			// �������Ա����
			StartAdmin(admin);
			return;
		}
		break;

	default:
		break;
	}

	// ��֤ʧ��
	cout << "��֤��¼ʧ�ܣ�" << endl;
	CleanAndPause();
}
