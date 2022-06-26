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

void Controller::ParseRoom()
{
	// ��ȡroom�ļ�
	ifstream ifs(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ����
	rooms.clear();
	Room room;
	while (ifs >> room.id && ifs >> room.capcity)
		rooms.push_back(room);

	// �ر��ļ�
	ifs.close();
}

void Controller::ParseOrder()
{
	// ��ȡ�ļ�
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ����
	this->orders.clear();
	Order o;
	string name;
	int id, room, week, time, n_status;
	while (ifs >> week && ifs >> time && ifs >> id && ifs >> name && ifs >> room && ifs >> n_status)
	{
		o = Order(name, id, week, time, room, (Order::Status)n_status);
		this->orders.insert(make_pair(id, o));
	}

	// �ر��ļ�
	ifs.close();
}

void Controller::StartStudent(Student& stu)
{
	int ipt = 0;
	do
	{
		// ��ʾҳ��
		stu.OpenMenu();
		cin >> ipt;
		switch (ipt)
		{
		case 1:	// ����ԤԼ
			stu.ApplyOrder(this->rooms);
			// ˢ������orders
			ParseOrder();
			break;

		case 2:	// �鿴�ҵ�ԤԼ
			stu.ShowMyOrder(this->orders);
			break;

		case 3:	// �鿴����ԤԼ
			stu.ShowAllOrder(this->orders);
			break;

		case 4:	// ȡ��ԤԼ
			stu.CancelOrder(this->orders);
			// ˢ������orders
			ParseOrder();
			break;

		case 0:	// ע����¼
			Logout();
			break;

		default:
			break;
		}
	} while (ipt);
}

void Controller::StartTeacher(Teacher& teacher)
{
	int ipt = 0;
	vector<Order> v;
	do
	{
		// ��ʾҳ��
		teacher.OpenMenu();
		cin >> ipt;
		switch (ipt)
		{
		case 0:	// ע���˺�
			Logout();
			break;
			
		case 1:	// �鿴����ԤԼ
			teacher.ShowAllOrder(this->orders);
			break;

		case 2:	// ���ԤԼ
			v = ToVector(this->orders);
			teacher.ValidOrder(v);
			ParseOrder();
			break;

		default:
			break;
		}
	} while (ipt);
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
			Logout();
			break;

		case 1: // ����˺�
			admin.AddPerson();
			// ˢ������
			ParseStudent();
			ParseTeacher();
			break;

		case 2: // �鿴�˺�
			admin.ShowPerson(this->stus, this->teachers);
			break;

		case 3: // �鿴����
			admin.ShowRoomInfo(this->rooms);
			break;

		case 4: // ���ԤԼ
			admin.ClearFile();
			// ˢ������orders
			ParseOrder();
			break;

		default:
			break;
		}
	} while (ipt);
}

void Controller::Logout()
{
	cout << "ע���ɹ���" << endl;
	CleanAndPause();
}

vector<Order> Controller::ToVector(multimap<int, Order>& orders)
{
	vector<Order> res;
	for (multimap<int, Order>::const_iterator itor = orders.begin(); itor != orders.end(); itor++)
		res.push_back(itor->second);
	return res;
}

Controller::Controller()
{
	// ������������
	ParseAdmin();
	ParseStudent();
	ParseTeacher();
	ParseRoom();
	ParseOrder();
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
		// ѧ�����
	case Identity::IdentityType::STU:
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

		// ��ʦ���
	case Identity::IdentityType::TEACHER:
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

		// ����Ա���
	case Identity::IdentityType::ADMIN:
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
